#!/usr/bin/env python3
"""The matching plan (config/plan.toml) joined with the objdiff report: progress, claims, next item.

    python3 tools/plan.py                 # stages, the current stage's items, claims, warnings, yield
    python3 tools/plan.py --json
    python3 tools/plan.py --next          # the next item id, its units and its functions left
    python3 tools/plan.py --item hubs     # one item's functions left
    python3 tools/plan.py --release hubs  # drop this checkout's claim record for an item
    python3 tools/plan.py --park "fn_X=best 45/81: mismatch; next: idea" [--park ...]
                                          # append [[parked]] rows to config/plan.toml
    python3 tools/plan.py --no-remote     # skip the GitHub open-PR query

A function is matched when its `fuzzy_match_percent` in build/GL5E4F/report.json is 100; it
is strict-only when it scores below 100% but passes `verify_fn.py --strict-symbols` (gap 9:
it waits on `.rodata` layout for promotion, not on matching; `strict_gap.verified()`, cached
per build). An item is closed when each of its functions is matched, strict-only or listed in
`[[parked]]`, a stage when
all its items are closed, and the current stage is the first one not closed and not marked
`alongside = true`. An alongside stage (stage 0, the CodeWarrior SDK residue) does not wait on
the call graph: its open items are worked beside the current stage's and come first in order. The `data` item
closes when the report's data bytes are all matched.

Claims: `claim(ID)` (run by `kickoff.py --start --item ID`) writes
`<git common dir>/lsw1-plan-claims/ID.json`, which every local worktree sees. A local or origin
branch or an open PR named `t3/plan-ID` also claims the item, as does a legacy
`t3/sprint-<unit>` branch for an item listing that unit. A record is stale (ignored) when its
worktree is gone, its branch is gone, its branch gained commits since the claim and they are
merged into origin/main, or it has outlived its run: an unfinished record expires CLAIM_HOURS
after the claim (an unattended run lasts about an hour, and its worktree outlives it), and a
record `sprint_finish.py` marked finished holds only while its branch has an open PR, at most
FINISHED_HOURS. This checkout's own claim is "mine", not taken.

`active_items()` ranks every open, unblocked, unclaimed item (stages are a priority, not a
gate): items with a function under QUICK_SIZE in the alongside and current stages, then quick
items of later stages, then the parked-retry lane, then the rest of the current stage, then the
rest of later stages. A later-stage item is flagged as look-ahead. `next_item()` is the first.
`kickoff.py --start --item` accepts any active item.

The parked-retry lane is the synthetic item `parked-retry` (stage `retry`): parked functions
whose reason records a best of at least RETRY_RATIO ("best N/M"), closest first. A run that
re-parks one (`--park` on a parked function) replaces its reason with a "retried:" one, which
leaves the lane, so each near miss gets one fresh attempt.
`plan_targets()` is what other tools default to: this checkout's claimed item, else the next item.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import time
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))

PLAN = ROOT / "config" / "plan.toml"
REPORT = ROOT / "build" / "GL5E4F" / "report.json"
PLAN_PREFIX = "t3/plan-"
CLAIMS = "lsw1-plan-claims"
CLAIM_HOURS = 3.0     # an unfinished claim expires: unattended runs last about an hour
FINISHED_HOURS = 6.0  # a finished claim holds this long at most while its PR is open
RETRY_ID, RETRY_STAGE = "parked-retry", "retry"
RETRY_RATIO = 0.85    # a park this close to a match is worth one fresh attempt
RETRIED = "retried: "


class PlanError(Exception):
    """The plan or the report is missing or unreadable."""


def git(*args: str, cwd: Path | None = None) -> str | None:
    try:
        out = subprocess.run(["git", *args], cwd=cwd or ROOT, capture_output=True, text=True, timeout=15)
    except (OSError, subprocess.TimeoutExpired):
        return None
    return out.stdout.strip() if out.returncode == 0 else None


# --- inputs ---------------------------------------------------------------------------------

def load_plan(path: Path | None = None) -> dict:
    path = path or PLAN
    try:
        return tomllib.loads(path.read_text())
    except (OSError, tomllib.TOMLDecodeError) as exc:
        raise PlanError(f"cannot read {path}: {exc}") from exc


def load_report(path: Path | None = None) -> dict:
    path = path or REPORT
    try:
        return json.loads(path.read_text())
    except (OSError, ValueError) as exc:
        raise PlanError(f"cannot read {path} ({exc}); run bash build.sh") from exc


def index_report(report: dict) -> dict:
    """{"units": {unit: [fn]}, "by_name": {name: [fn]}, "data": (matched, total)}; fn has name,
    unit, size, matched. Unit names lose the report's `main/` prefix."""
    units: dict[str, list[dict]] = {}
    by_name: dict[str, list[dict]] = {}
    for u in report.get("units", []):
        name = u["name"].removeprefix("main/")
        fns = units.setdefault(name, [])
        for f in u.get("functions", []):
            fn = {"name": f["name"], "unit": name, "size": int(f.get("size") or 0),
                  "matched": float(f.get("fuzzy_match_percent") or 0) >= 100.0}
            fns.append(fn)
            by_name.setdefault(f["name"], []).append(fn)
    m = report.get("measures", {})
    return {"units": units, "by_name": by_name,
            "data": (int(m.get("matched_data") or 0), int(m.get("total_data") or 0))}


def parked_names(plan: dict) -> dict[str, str]:
    return {p["function"]: p.get("reason", "") for p in plan.get("parked", []) if p.get("function")}


def park_closeness(reason: str) -> float | None:
    """The best N/M ratio a park reason records ("best 45/47", "Best 100/101 ..."), else None."""
    m = (re.search(r"(?i)\bbest\D{0,3}(\d+)\s*/\s*(\d+)", reason)
         or re.search(r"\b(\d+)\s*/\s*(\d+)\b", reason))
    if not m or not int(m[2]) or int(m[1]) > int(m[2]):
        return None
    return int(m[1]) / int(m[2])


def retry_item(parked: dict[str, str], idx: dict, strict: set[str] | frozenset) -> dict:
    """The parked-retry lane: unmatched parked functions at RETRY_RATIO or closer that were not
    retried yet, closest first."""
    rows = []
    for name, reason in parked.items():
        ratio = park_closeness(reason)
        fns = idx["by_name"].get(name, [])
        if (ratio is None or ratio < RETRY_RATIO or reason.startswith(RETRIED) or name in strict
                or not fns or all(f["matched"] for f in fns)):
            continue
        rows.append((-ratio, fns[0]["size"], name))
    rows.sort()
    return {"id": RETRY_ID, "stage": RETRY_STAGE, "units": sorted({f["unit"] for _, _, n in rows
                                                                  for f in idx["by_name"][n]}),
            "blocked": None, "data": False, "whole_units": False, "retry": True,
            "note": f"parked functions at {RETRY_RATIO:.0%} or closer, one fresh attempt each",
            "functions": [n for _, _, n in rows], "fn_left": len(rows),
            "closeness": {n: round(-r, 3) for r, _, n in rows},
            "bytes_left": sum(s for _, s, _ in rows), "min_size": min((s for _, s, _ in rows), default=0),
            "parked": [], "strict_only": [], "closed": not rows}


# --- evaluation -----------------------------------------------------------------------------

def item_functions(item: dict, idx: dict) -> tuple[list[dict], list[str]]:
    """(the item's report functions, names of its units/functions the report lacks)."""
    fns, missing = [], []
    for unit in item.get("units", []):
        if unit in idx["units"]:
            fns.extend(idx["units"][unit])
        else:
            missing.append(f"unit {unit}")
    for name in item.get("functions", []):
        if name in idx["by_name"]:
            fns.extend(idx["by_name"][name])
        else:
            missing.append(f"function {name}")
    return fns, missing


def evaluate(plan: dict, report: dict, strict: set[str] | frozenset = frozenset()) -> dict:
    """Per-item and per-stage figures, the current stage and the plan-revision warnings that
    need only the plan and the report (claims and bench runs add more in status()). STRICT names
    the strict-only functions: done for matching, so not targets."""
    idx = index_report(report)
    parked = parked_names(plan)
    stages, covered, warnings = [], set(), []
    for stage in plan.get("stage", []):
        items = []
        for item in stage.get("item", []):
            rec = {"id": item["id"], "stage": stage["id"], "units": list(item.get("units", [])),
                   "blocked": item.get("blocked"), "note": item.get("note"), "data": bool(item.get("data")),
                   "whole_units": bool(item.get("units"))}
            if rec["data"]:
                matched, total = idx["data"]
                rec.update(functions=[], fn_left=0, bytes_left=total - matched, min_size=0, parked=[], strict_only=[],
                           closed=total > 0 and matched >= total)
            else:
                fns, missing = item_functions(item, idx)
                covered.update((f["unit"], f["name"]) for f in fns)
                left = [f for f in fns if not f["matched"]]
                todo = [f for f in left if f["name"] not in parked and f["name"] not in strict]
                rec.update(functions=[f["name"] for f in todo], fn_left=len(todo),
                           strict_only=sorted({f["name"] for f in left if f["name"] in strict
                                               and f["name"] not in parked}),
                           bytes_left=sum(f["size"] for f in todo),
                           min_size=min((f["size"] for f in todo), default=0),
                           parked=sorted({f["name"] for f in left if f["name"] in parked}),
                           units=rec["units"] or sorted({f["unit"] for f in fns}), closed=not todo)
                for m in missing:
                    warnings.append(f"item {item['id']} names {m}, which the report lacks")
            items.append(rec)
        stages.append({"id": stage["id"], "title": stage.get("title", ""), "items": items,
                       "alongside": bool(stage.get("alongside")),
                       "closed": all(i["closed"] for i in items),
                       "fn_left": sum(i["fn_left"] for i in items),
                       "bytes_left": sum(i["bytes_left"] for i in items),
                       "data": any(i["data"] for i in items)})
    uncovered: dict[str, int] = {}
    for unit, fns in idx["units"].items():
        for f in fns:
            if not f["matched"] and (unit, f["name"]) not in covered:
                uncovered[unit] = uncovered.get(unit, 0) + 1
    for unit, n in sorted(uncovered.items()):
        warnings.append(f"{n} unmatched function(s) of {unit} are in no item")
    current = (next((s for s in stages if not s["closed"] and not s["alongside"]), None)
               or next((s for s in stages if not s["closed"]), None))
    retry = retry_item(parked, idx, strict)
    stages.append({"id": RETRY_STAGE, "title": "Parked near misses (retry lane)", "items": [retry],
                   "alongside": False, "retry": True, "closed": retry["closed"], "fn_left": retry["fn_left"],
                   "bytes_left": retry["bytes_left"], "data": False})
    return {"revision": plan.get("revision"), "stages": stages, "current": current["id"] if current else None,
            "warnings": warnings, "parked": parked}


def find_item(state: dict, item_id: str) -> dict | None:
    return next((i for s in state["stages"] for i in s["items"] if i["id"] == item_id), None)


def stage_of(state: dict, stage_id: str | None) -> dict | None:
    return next((s for s in state["stages"] if s["id"] == stage_id), None)


# --- claims ---------------------------------------------------------------------------------

def claims_dir(root: Path | None = None) -> Path:
    common = git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=root or ROOT)
    return Path(common or (root or ROOT) / ".git") / CLAIMS


def current_branch(root: Path | None = None) -> str:
    return git("branch", "--show-current", cwd=root or ROOT) or ""


def claim(item_id: str, root: Path | None = None, now: float | None = None) -> Path:
    """Record this checkout's claim on ITEM_ID; returns the record path."""
    root = (root or ROOT).resolve()
    path = claims_dir(root) / f"{item_id}.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    record = {"item": item_id, "branch": current_branch(root), "worktree": str(root),
              "head": git("rev-parse", "HEAD", cwd=root), "time": round(now or time.time())}
    path.write_text(json.dumps(record, indent=2) + "\n")
    return path


def release(item_id: str, root: Path | None = None) -> bool:
    path = claims_dir(root) / f"{item_id}.json"
    if path.is_file():
        path.unlink()
        return True
    return False


def finish_claims(root: Path | None = None, now: float | None = None) -> list[str]:
    """Mark this checkout's claim records finished (run by sprint_finish.py); the items they
    name. A finished record then holds only while the branch has an open PR."""
    root = (root or ROOT).resolve()
    d, done = claims_dir(root), []
    for path in sorted(d.glob("*.json")) if d.is_dir() else []:
        try:
            rec = json.loads(path.read_text())
        except (OSError, ValueError):
            continue
        if rec.get("worktree") != str(root) or rec.get("finished"):
            continue
        rec["finished"] = round(now or time.time())
        path.write_text(json.dumps(rec, indent=2) + "\n")
        done.append(rec.get("item") or path.stem)
    return done


def record_stale(rec: dict, root: Path | None = None, open_heads: set[str] | None = None,
                 now: float | None = None) -> str | None:
    """Why a claim record no longer holds, or None while it does. OPEN_HEADS are the head
    branches of open PRs, None when GitHub was not asked."""
    tree = rec.get("worktree")
    if not tree or not Path(tree).exists():
        return f"worktree {tree} is gone"
    now = now or time.time()
    if rec.get("finished"):
        hours = (now - rec["finished"]) / 3600
        if hours > FINISHED_HOURS:
            return f"finished {hours:.1f} h ago"
        if open_heads is not None and rec.get("branch") not in open_heads:
            return "finished with no open PR"
    elif rec.get("time") and (now - rec["time"]) / 3600 > CLAIM_HOURS:
        return f"expired: claimed {(now - rec['time']) / 3600:.1f} h ago and never finished"
    branch = rec.get("branch")
    if not branch:
        return None
    tip = git("rev-parse", "--verify", "-q", f"refs/heads/{branch}", cwd=root)
    if tip is None:
        return f"branch {branch} is gone"
    # A fresh branch is an ancestor of origin/main before its first commit; only commits made
    # after the claim and then merged end it.
    if tip != rec.get("head") and git("merge-base", "--is-ancestor", tip, "origin/main", cwd=root) is not None:
        return f"branch {branch} is merged into origin/main"
    return None


def open_pr_heads() -> set[str] | None:
    """Head branch names of the repository's open PRs, or None when gh cannot answer."""
    import next_target as nt
    try:
        out = subprocess.run(["gh", "pr", "list", "--repo", nt.REPO, "--state", "open", "--limit", "200",
                              "--json", "headRefName", "--jq", ".[].headRefName"],
                             cwd=ROOT, capture_output=True, text=True, timeout=15)
    except (OSError, subprocess.TimeoutExpired):
        return None
    return set(out.stdout.split()) if out.returncode == 0 else None


def read_records(root: Path | None = None, open_heads: set[str] | None = None,
                 now: float | None = None) -> list[dict]:
    out = []
    d = claims_dir(root)
    for path in sorted(d.glob("*.json")) if d.is_dir() else []:
        try:
            rec = json.loads(path.read_text())
        except (OSError, ValueError):
            continue
        rec.setdefault("item", path.stem)
        rec["path"] = str(path)
        rec["stale"] = record_stale(rec, root, open_heads, now)
        out.append(rec)
    return out


def plan_branches(remote: bool = True) -> dict[str, str]:
    """{item: source} for unmerged local/origin branches and open PRs named t3/plan-ITEM,
    via next_target's ownership query; the current branch is included (it is "mine")."""
    import next_target as nt
    return {name: "branch or PR" for name in nt.active_branches(PLAN_PREFIX, remote=remote, include_current=True)}


def claims(state: dict, remote: bool = True, root: Path | None = None, records: list[dict] | None = None,
           branches: dict[str, str] | None = None, sprints: set[str] | None = None) -> dict:
    """{"items": {item: {"by", "mine"}}, "stale": [records]} from claim records, t3/plan-* branches
    and PRs, and legacy t3/sprint-* branches owning one of an item's units."""
    root = (root or ROOT).resolve()
    me, branch = str(root), current_branch(root)
    records = read_records(root, open_pr_heads() if remote else None) if records is None else records
    branches = plan_branches(remote) if branches is None else branches
    if sprints is None:
        import next_target as nt
        sprints = nt.sprint_branches(remote=remote)
    out: dict[str, dict] = {}
    stale = []

    def add(item, by, mine):
        cur = out.get(item)
        if cur is None or (mine and not cur["mine"]):
            out[item] = {"by": by, "mine": mine}
    # Keep finished claims for ownership, but route this checkout to its unfinished claim first.
    for rec in sorted(records, key=lambda rec: bool(rec.get("finished"))):
        if rec.get("stale"):
            stale.append(rec)
            continue
        mine = rec.get("worktree") == me
        add(rec["item"], f"{rec.get('branch') or '?'} ({rec.get('worktree')})", mine)
    if branch.startswith(PLAN_PREFIX):
        add(branch[len(PLAN_PREFIX):], f"current branch {branch}", True)
    for item, src in branches.items():
        add(item, f"{PLAN_PREFIX}{item} {src}", branch == PLAN_PREFIX + item)
    if sprints:
        import next_target as nt
        whole = [i for s in state["stages"] for i in s["items"] if i["whole_units"]]
        units = frozenset(u for i in whole for u in i["units"])
        for i in whole:
            for u in i["units"]:
                if nt.owned_by_sprint(u, sprints, units):
                    add(i["id"], f"t3/sprint-* owns {u}", False)
    return {"items": out, "stale": stale}


def mine(cl: dict) -> str | None:
    return next((item for item, c in cl["items"].items() if c["mine"]), None)


def taken(cl: dict, item_id: str) -> bool:
    c = cl["items"].get(item_id)
    return bool(c and not c["mine"])


def open_items(stage: dict) -> list[dict]:
    return [i for i in stage["items"] if not i["closed"] and not i["blocked"]]


def next_item(state: dict, cl: dict) -> dict | None:
    """{"item", "stage", "lookahead"} or None: see the module docstring. This checkout's own
    claimed item comes first while it is open."""
    own = mine(cl)
    if own:
        item = find_item(state, own)
        if item and not item["closed"]:
            return {"item": item, "stage": item["stage"], "lookahead": False, "mine": True}
    active = active_items(state, cl)
    if not active:
        return None
    item, lookahead = active[0]
    return {"item": item, "stage": item["stage"], "lookahead": lookahead, "mine": False}


QUICK_SIZE = 0x180  # bytes: kickoff's HARD_SIZE; a smaller function can match in one pass


def quick(item: dict) -> bool:
    """The item has a function left under QUICK_SIZE (or is the data item)."""
    return bool(item.get("data")) or 0 < item.get("min_size", 0) < QUICK_SIZE


def active_items(state: dict, cl: dict) -> list[tuple[dict, bool]]:
    """[(item, lookahead)] for every open, unblocked, unclaimed item, best first. Stages are a
    priority, not a gate: an unattended run that plateaus on a large function parks it and moves
    on, so quick work anywhere beats a large function of the current stage. Tiers, each in plan
    order: quick items of the alongside and current stages; quick items of later stages; the
    parked-retry lane; the rest of the alongside and current stages; the rest of later stages."""
    now, later, retry, seen_current = [], [], [], False
    for stage in state["stages"]:
        if stage["closed"]:
            continue
        free = [i for i in open_items(stage) if not taken(cl, i["id"])]
        if stage.get("retry"):
            retry += free
        elif not seen_current and (stage["alongside"] or stage["id"] == state["current"]):
            now += free
        else:
            later += free
        seen_current = seen_current or stage["id"] == state["current"]
    tiers = ([(i, False) for i in now if quick(i)] + [(i, True) for i in later if quick(i)]
             + [(i, False) for i in retry]
             + [(i, False) for i in now if not quick(i)] + [(i, True) for i in later if not quick(i)])
    return tiers


def batch_items(state: dict, cl: dict, n: int) -> list[tuple[dict, bool]]:
    """Up to N distinct free items for parallel children, one item each, in active_items() order."""
    return active_items(state, cl)[:n]


# --- bench yield ----------------------------------------------------------------------------

def bench_records() -> list[dict]:
    try:
        import sprint_bench as sb
        return sb.compare()
    except Exception:
        return []


def stage_yield(state: dict, records: list[dict]) -> dict[str, dict]:
    """{stage: {runs, zero (runs that matched nothing), verified, verified_bytes, active_hours, fn_per_hour, bytes_per_hour}} over
    finished bench runs that carry an item id."""
    out: dict[str, dict] = {}
    for rec in records:
        item = find_item(state, rec.get("item") or "")
        if not item or not rec.get("active_seconds") or rec.get("new_verified") is None:
            continue
        y = out.setdefault(item["stage"], {"runs": 0, "zero": 0, "verified": 0, "verified_bytes": 0,
                                           "active_hours": 0.0})
        y["runs"] += 1
        y["zero"] += not rec["new_verified"]
        y["verified"] += rec["new_verified"] or 0
        y["verified_bytes"] += rec.get("new_verified_bytes") or 0
        y["active_hours"] += rec["active_seconds"] / 3600
    for y in out.values():
        y["fn_per_hour"] = y["verified"] / y["active_hours"]
        y["bytes_per_hour"] = y["verified_bytes"] / y["active_hours"]
    return out


# --- the joined view ------------------------------------------------------------------------

def strict_only(report: dict) -> set[str]:
    """Strict-only names for the built report; empty when the check cannot run."""
    try:
        import strict_gap
        return strict_gap.verified(REPORT, report)
    except Exception as exc:  # a missing build object must not stop the plan
        print(f"warning: strict-only check skipped ({exc})", file=sys.stderr)
        return set()


def status(remote: bool = True, plan: dict | None = None, report: dict | None = None,
           cl: dict | None = None, records: list[dict] | None = None,
           strict: set[str] | None = None) -> dict:
    """STRICT defaults to the built report's strict-only set, or none for a given REPORT."""
    if report is None:
        report = load_report()
        strict = strict_only(report) if strict is None else strict
    state = evaluate(plan if plan is not None else load_plan(), report, strict or frozenset())
    cl = claims(state, remote=remote) if cl is None else cl
    records = bench_records() if records is None else records
    state["claims"] = cl
    state["next"] = next_item(state, cl)
    state["mine"] = mine(cl)
    if state["current"] and not active_items(state, cl):
        state["warnings"].append("no open item is free (what is left is claimed, parked or blocked)")
    state["yield"] = stage_yield(state, records)
    return state


def target_item(state: dict) -> dict | None:
    """This checkout's claimed item, else the next item."""
    if state.get("mine"):
        item = find_item(state, state["mine"])
        if item:
            return item
    return state["next"]["item"] if state.get("next") else None


def functions_for(item_id: str, state: dict | None = None) -> list[str]:
    """ITEM_ID's unmatched, unparked function names."""
    if state is None:
        report = load_report()
        state = evaluate(load_plan(), report, strict_only(report))
    item = find_item(state, item_id)
    if item is None:
        raise PlanError(f"no item {item_id} in {PLAN.relative_to(ROOT)}")
    return list(item["functions"])


def plan_targets(remote: bool = False, state: dict | None = None) -> dict:
    """{"item": id or None, "mine": bool, "functions": [...], "stage": [names of the current
    stage's open items]}: the default target set for other tools. Never raises; an unreadable
    plan or report gives an empty set with an "error"."""
    try:
        state = state or status(remote=remote, records=[])
    except PlanError as exc:
        return {"item": None, "mine": False, "functions": [], "stage": [], "error": str(exc)}
    item = target_item(state)
    cur = stage_of(state, item["stage"] if item else state["current"])
    stage = [n for i in (open_items(cur) if cur else []) for n in i["functions"]]
    return {"item": item["id"] if item else None, "stage_id": cur["id"] if cur else None,
            "mine": bool(item and item["id"] == state.get("mine")),
            "functions": list(item["functions"]) if item else [], "stage": stage}


# --- CLI ------------------------------------------------------------------------------------

def warning_lines(state: dict) -> list[str]:
    return [f"plan needs revision: {w}" for w in state["warnings"]]


def describe_next(state: dict) -> str:
    nxt = state["next"]
    if not nxt:
        return "no recommendable item"
    i = nxt["item"]
    tag = (" (yours)" if nxt.get("mine") else " (retry lane: parked near misses, closest first)" if i.get("retry")
           else " (later stage: quick work ahead of the current stage's large functions)" if nxt["lookahead"] else "")
    left = (f"{i['bytes_left']:,} data bytes left" if i["data"]
            else f"{i['fn_left']} functions, {i['bytes_left']:,} bytes left")
    return f"stage {nxt['stage']}, item {i['id']}{tag}: {left}"


def print_status(state: dict) -> None:
    print(f"Plan revision {state['revision']} (config/plan.toml); current stage: {state['current'] or 'none'}")
    print(f"\n{'stage':<20}{'items':>6}{'open':>6}{'fn left':>9}{'bytes left':>12}  state")
    for s in state["stages"]:
        n_open = sum(1 for i in s["items"] if not i["closed"])
        mark = "closed" if s["closed"] else ("current" if s["id"] == state["current"]
                                             else "alongside" if s["alongside"] else "retry lane" if s.get("retry")
                                             else "")
        mark += " (data bytes)" if s["data"] else ""
        print(f"{s['id']:<20}{len(s['items']):>6}{n_open:>6}{s['fn_left']:>9}{s['bytes_left']:>12,}  {mark}")
    shown = [s for s in state["stages"] if not s["closed"] and s["alongside"]
             and state["stages"].index(s) < state["stages"].index(stage_of(state, state["current"]))]
    retry = [s for s in state["stages"] if s.get("retry") and not s["closed"]]
    for cur in shown + [s for s in [stage_of(state, state["current"])] if s] + retry:
        print(f"\nStage {cur['id']} ({cur['title']}{', alongside' if cur['alongside'] else ''}):")
        print(f"  {'item':<18}{'fn left':>8}{'bytes left':>12}  claim")
        for i in cur["items"]:
            c = state["claims"]["items"].get(i["id"])
            if i["closed"]:
                who = "closed"
            elif i["blocked"]:
                who = f"blocked: {i['blocked']}"
            elif c:
                who = ("mine: " if c["mine"] else "claimed: ") + c["by"]
            else:
                who = "-"
            extra = f" ({len(i['parked'])} parked)" if i["parked"] else ""
            extra += f" ({len(i['strict_only'])} strict-only)" if i.get("strict_only") else ""
            print(f"  {i['id']:<18}{i['fn_left']:>8}{i['bytes_left']:>12,}  {who}{extra}")
    for rec in state["claims"]["stale"]:
        print(f"stale claim ignored: {rec['item']} ({rec['stale']}; {rec['path']})")
    print(f"\nNext: {describe_next(state)}")
    if state["next"]:
        print(f"  python3 tools/kickoff.py --start --item {state['next']['item']['id']}")
    for line in warning_lines(state):
        print(line)
    print("\nYield per stage (finished item bench runs):")
    if not state["yield"]:
        print("  no measurement yet (kickoff.py --start --item ID opens a bench run)")
    for sid, y in state["yield"].items():
        print(f"  {sid}: {y['runs']} run(s) ({y.get('zero', 0)} matched nothing), {y['verified']} fn / {y['verified_bytes']:,} B in "
              f"{y['active_hours']:.1f} active h = {y['fn_per_hour']:.1f} fn/h, {y['bytes_per_hour']:,.0f} B/h")


def jsonable(state: dict) -> dict:
    out = dict(state)
    out["claims"] = {"items": state["claims"]["items"], "stale": state["claims"]["stale"]}
    return out


def park_functions(rows: list[str], path: Path | None = None) -> tuple[list[str], list[str]]:
    """Record plateaus ("FN=reason") in the plan: append a `[[parked]]` row for a new name, and
    replace the reason of an already parked one with a "retried: " reason (it leaves the retry
    lane). Returns (names added, names re-parked). A run that matches nothing still leaves its
    plateau here, so the next run does not retry the same functions blind."""
    path = path or PLAN
    parsed = []
    for row in rows:
        fn, sep, reason = row.partition("=")
        fn, reason = fn.strip(), reason.strip()
        if not sep or not fn or not reason:
            raise PlanError(f"--park needs FN=reason (best score, mismatch, next hypothesis): {row!r}")
        parsed.append((fn, reason))
    text = path.read_text()
    have = {p["function"] for p in tomllib.loads(text).get("parked", []) if p.get("function")}
    out, added, again = [], [], []
    for fn, reason in parsed:
        if fn in have:
            new = reason if reason.startswith(RETRIED) else RETRIED + reason
            pat = re.compile(rf'(\[\[parked\]\]\nfunction = {re.escape(json.dumps(fn))}\nreason = ).*')
            text, n = pat.subn(lambda m: m[1] + json.dumps(new), text, count=1)
            if n:
                again.append(fn)
            continue
        have.add(fn)
        added.append(fn)
        out.append(f'[[parked]]\nfunction = {json.dumps(fn)}\nreason = {json.dumps(reason)}\n')
    if out:
        text = text.rstrip("\n") + "\n\n" + "\n".join(out)
    if added or again:
        tomllib.loads(text)  # never write a plan that no longer parses
        path.write_text(text)
    return added, again


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--next", action="store_true", help="print the next item and its targets")
    ap.add_argument("--item", help="print one item's targets")
    ap.add_argument("--batch", type=int, metavar="N",
                    help="list N distinct free items, one per child, with their claim commands")
    ap.add_argument("--release", metavar="ID", help="remove the claim record for ID")
    ap.add_argument("--park", action="append", default=[], metavar="FN=REASON",
                    help="record a plateau as a [[parked]] row in config/plan.toml")
    ap.add_argument("--no-remote", action="store_true", help="do not ask GitHub for open t3/plan-* PRs")
    args = ap.parse_args(argv)
    if args.park:
        try:
            added, again = park_functions(args.park)
        except PlanError as exc:
            print(f"error: {exc}", file=sys.stderr)
            return 2
        print(f"parked {len(added)} in config/plan.toml: {' '.join(added) or '-'}")
        if again:
            print(f"re-parked {len(again)} (reason replaced, marked retried): {' '.join(again)}")
        return 0
    if args.release:
        print(f"released {args.release}" if release(args.release) else f"no claim record for {args.release}")
        return 0
    try:
        state = status(remote=not args.no_remote)
    except PlanError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    if args.batch:
        rows = batch_items(state, state["claims"], args.batch)
        if args.json:
            print(json.dumps([dict(i, lookahead=la) for i, la in rows], indent=2))
            return 0
        if not rows:
            print("error: no free item", file=sys.stderr)
            return 2
        for item, la in rows:
            tag = " (retry lane)" if item.get("retry") else " (later stage)" if la else ""
            print(f"{item['id']:<20} {item['stage']:<16} {item['fn_left']:>4} fn {item['bytes_left']:>8,} B{tag}"
                  f"   python3 tools/kickoff.py --start --item {item['id']}")
        if len(rows) < args.batch:
            print(f"only {len(rows)} free item(s); give no child a single function instead", file=sys.stderr)
        return 0
    if args.next or args.item:
        item = state["next"]["item"] if args.next and state["next"] else find_item(state, args.item or "")
        if item is None:
            print("error: " + (f"no item {args.item}" if args.item else "no recommendable item"), file=sys.stderr)
            return 2
        if args.json:
            print(json.dumps(item, indent=2))
            return 0
        print(describe_next(state) if args.next else f"item {item['id']} (stage {item['stage']})")
        if item["units"]:
            print("units: " + " ".join(item["units"]))
        if item["blocked"]:
            print(f"blocked: {item['blocked']}")
        print(f"functions left ({item['fn_left']}): " + " ".join(item["functions"]))
        if item["parked"]:
            print("parked: " + " ".join(item["parked"]))
        if item.get("closeness"):
            print("closeness: " + " ".join(f"{n}={c:.0%}" for n, c in item["closeness"].items()))
        if item.get("strict_only"):
            print("strict-only (verified; awaits promotion): " + " ".join(item["strict_only"]))
        return 0
    if args.json:
        print(json.dumps(jsonable(state), indent=2, default=str))
        return 0
    print_status(state)
    return 0


if __name__ == "__main__":
    sys.exit(main())
