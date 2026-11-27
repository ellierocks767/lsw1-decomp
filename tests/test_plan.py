"""plan.py: closure with parked functions, current stage, ranked items with claims, the
parked-retry lane, claim expiry, re-parking, revision warnings and yield. Fixture plan/report dicts; no retail inputs."""
import json
import subprocess
import tempfile
import unittest
from pathlib import Path

from tools import plan


def fn(name, size, matched=False):
    return {"name": name, "size": str(size), **({"fuzzy_match_percent": 100.0} if matched else
                                                {"fuzzy_match_percent": 50.0})}


def report(**units):
    return {"measures": {"matched_data": "40", "total_data": "100"},
            "units": [{"name": f"main/{u}", "functions": fns} for u, fns in units.items()]}


REPORT = report(**{
    "core/a": [fn("a1", 10, True), fn("a2", 20)],
    "core/b": [fn("b1", 30), fn("b2", 40)],
    "game/c": [fn("c1", 50), fn("c2", 60), fn("c3", 70, True)],
    "data_only": [],
})

PLAN = {
    "revision": 1,
    "parked": [{"function": "b2", "reason": "best 9/10"}],
    "stage": [
        {"id": "s1", "item": [{"id": "hub", "functions": ["c1"]},
                               {"id": "core", "units": ["core/a", "core/b"]}]},
        {"id": "s2", "item": [{"id": "game", "units": ["game/c"]},
                               {"id": "stuck", "units": [], "functions": [], "blocked": "no route"}]},
        {"id": "s3", "item": [{"id": "data", "data": True}]},
    ],
}

NO_CLAIMS = {"items": {}, "stale": []}


def state_with(cl=NO_CLAIMS, plan_=PLAN, report_=REPORT, records=()):
    return plan.status(plan=plan_, report=report_, cl=cl, records=list(records))


class EvaluateTests(unittest.TestCase):
    def test_items_close_on_matched_or_parked(self):
        s = plan.evaluate(PLAN, REPORT)
        core = plan.find_item(s, "core")
        self.assertEqual((core["functions"], core["fn_left"], core["bytes_left"]), (["a2", "b1"], 2, 50))
        self.assertEqual(core["parked"], ["b2"])
        self.assertFalse(core["closed"])
        self.assertEqual(plan.find_item(s, "hub")["units"], ["game/c"])
        data = plan.find_item(s, "data")
        self.assertEqual((data["bytes_left"], data["closed"]), (60, False))
        self.assertEqual(s["current"], "s1")
        done = report(**{"core/a": [fn("a2", 20, True)], "core/b": [fn("b1", 30, True), fn("b2", 40)],
                         "game/c": [fn("c1", 50, True), fn("c2", 60)]})
        s = plan.evaluate(PLAN, done)
        self.assertTrue(plan.find_item(s, "core")["closed"])  # b2 is parked
        self.assertTrue(plan.stage_of(s, "s1")["closed"])
        self.assertEqual(s["current"], "s2")

    def test_strict_only_functions_are_not_targets(self):
        s = plan.evaluate(PLAN, REPORT, {"b1", "b2"})
        core = plan.find_item(s, "core")
        self.assertEqual((core["functions"], core["bytes_left"], core["strict_only"]), (["a2"], 20, ["b1"]))
        self.assertEqual(core["parked"], ["b2"])  # parked wins over strict-only
        s = plan.evaluate(PLAN, report(**{"core/a": [fn("a2", 20, True)], "core/b": [fn("b1", 30)],
                                          "game/c": [fn("c1", 50, True)]}), {"b1"})
        self.assertTrue(plan.find_item(s, "core")["closed"])
        self.assertEqual(state_with()["stages"][0]["items"][1]["strict_only"], [])  # given REPORT: none

    def test_revision_warnings_for_missing_and_uncovered(self):
        p = json.loads(json.dumps(PLAN))
        p["stage"][0]["item"][0]["functions"].append("nope")
        p["stage"][0]["item"][1]["units"] = ["core/a", "core/zz"]
        warnings = plan.evaluate(p, REPORT)["warnings"]
        self.assertIn("item hub names function nope, which the report lacks", warnings)
        self.assertIn("item core names unit core/zz, which the report lacks", warnings)
        self.assertIn("2 unmatched function(s) of core/b are in no item", warnings)
        self.assertEqual(plan.evaluate(PLAN, REPORT)["warnings"], [])


class NextItemTests(unittest.TestCase):
    def test_first_open_item_then_lookahead_and_mine(self):
        s = state_with()
        self.assertEqual((s["next"]["item"]["id"], s["next"]["lookahead"]), ("hub", False))
        cl = {"items": {"hub": {"by": "x", "mine": False}}, "stale": []}
        self.assertEqual(state_with(cl)["next"]["item"]["id"], "core")
        cl["items"]["core"] = {"by": "y", "mine": False}
        s = state_with(cl)
        self.assertEqual((s["next"]["item"]["id"], s["next"]["stage"], s["next"]["lookahead"]), ("game", "s2", True))
        self.assertFalse(any("no open item is free" in w for w in s["warnings"]))
        cl["items"]["core"] = {"by": "me", "mine": True}
        s = state_with(cl)
        self.assertEqual((s["next"]["item"]["id"], s["next"]["mine"]), ("core", True))
        targets = plan.plan_targets(state=s)
        self.assertEqual((targets["item"], targets["mine"], targets["functions"]), ("core", True, ["a2", "b1"]))
        self.assertEqual(targets["stage"], ["c1", "a2", "b1"])

    def test_alongside_stage_runs_beside_the_current_one(self):
        p = json.loads(json.dumps(PLAN))
        p["stage"].insert(0, {"id": "s0", "alongside": True, "item": [{"id": "side", "units": ["game/c"]}]})
        s = state_with(plan_=p)
        self.assertEqual(s["current"], "s1")
        self.assertEqual(s["next"]["item"]["id"], "side")
        active = [i["id"] for i, la in plan.active_items(s, NO_CLAIMS)]
        self.assertEqual(active, ["side", "hub", "core", "game", "data", "parked-retry"])
        cl = {"items": {k: {"by": "x", "mine": False} for k in ("side", "hub", "core")}, "stale": []}
        self.assertEqual([(i["id"], la) for i, la in plan.active_items(s, cl)],
                         [("game", True), ("data", True), ("parked-retry", False)])
        done = report(**{"core/a": [], "core/b": [], "game/c": [fn("c1", 50, True), fn("c2", 60)]})
        s = state_with(plan_=p, report_=done)
        self.assertEqual(s["current"], "s2")
        self.assertEqual(s["next"]["item"]["id"], "side")  # still open, still worked

    def test_items_with_quick_functions_come_first(self):
        big = report(**{"core/a": [fn("a1", 10, True), fn("a2", 0x400)],
                        "core/b": [fn("b1", 0x500), fn("b2", 40)],
                        "game/c": [fn("c1", 0x200), fn("c2", 60), fn("c3", 70, True)], "data_only": []})
        s = state_with(report_=big)  # b2 is parked: hub (c1) and core (a2, b1) are all large
        # quick work in later stages, then the retry lane (b2 at 9/10), then the large current items
        self.assertEqual([(i["id"], la) for i, la in plan.active_items(s, NO_CLAIMS)],
                         [("game", True), ("data", True), ("parked-retry", False), ("hub", False), ("core", False)])
        p = json.loads(json.dumps(PLAN))
        p["parked"] = [{"function": "a2", "reason": "best 1/2"}]  # core now has 40-byte b2 left
        s = state_with(plan_=p, report_=big)
        self.assertEqual([i["id"] for i, _ in plan.active_items(s, NO_CLAIMS)], ["core", "game", "data", "hub"])
        self.assertEqual(s["next"]["item"]["id"], "core")
        self.assertIn("later stage", plan.describe_next(state_with(report_=big)))

    def test_batch_lists_distinct_free_items_then_looks_ahead(self):
        cl = {"items": {"hub": {"by": "x", "mine": False}}, "stale": []}
        rows = [(i["id"], la) for i, la in plan.batch_items(state_with(cl), cl, 5)]
        self.assertEqual(rows, [("core", False), ("game", True), ("data", True), ("parked-retry", False)])
        self.assertEqual(len(plan.batch_items(state_with(), NO_CLAIMS, 2)), 2)

    def test_blocked_items_are_never_recommended(self):
        p = json.loads(json.dumps(PLAN))
        p["stage"][1]["item"][1] = {"id": "stuck", "units": ["game/c"], "blocked": "no route"}
        p["stage"][1]["item"].pop(0)
        done = report(**{"core/a": [], "core/b": [], "game/c": [fn("c1", 50, True), fn("c2", 60)]})
        s = state_with(plan_=p, report_=done)
        self.assertEqual(s["current"], "s2")
        self.assertEqual(s["next"]["item"]["id"], "data")  # look-ahead past the blocked stage
        self.assertTrue(s["next"]["lookahead"])
        self.assertNotIn("stuck", [i["id"] for i, _ in plan.active_items(s, NO_CLAIMS)])

    def test_zero_verified_bench_run_and_yield(self):
        records = [{"run_id": "r1", "item": "core", "verified": 0, "verified_bytes": 0, "new_verified": 0, "new_verified_bytes": 0, "active_seconds": 1800},
                   {"run_id": "r2", "item": "hub", "verified": 4, "verified_bytes": 400, "new_verified": 4, "new_verified_bytes": 400, "active_seconds": 1800},
                   {"run_id": "r3", "unit": "old", "verified": 0, "active_seconds": 60}]
        s = state_with(records=records)
        self.assertFalse([w for w in s["warnings"] if "bench run" in w])  # counted in yield instead
        y = s["yield"]["s1"]
        self.assertEqual((y["runs"], y["zero"], y["verified"], y["fn_per_hour"], y["bytes_per_hour"]),
                         (2, 1, 4, 4.0, 400.0))

    def test_no_free_item_warns(self):
        cl = {"items": {k: {"by": "x", "mine": False} for k in ("hub", "core", "game", "data", "parked-retry")},
              "stale": []}
        s = state_with(cl)
        self.assertIsNone(s["next"])
        self.assertTrue(any("no open item is free" in w for w in s["warnings"]))


class RetryLaneTests(unittest.TestCase):
    def test_closeness_parses_the_recorded_best(self):
        self.assertEqual(plan.park_closeness("best 45/50: lhax"), 0.9)
        self.assertEqual(plan.park_closeness("Best: 99/100 after permuter"), 0.99)
        self.assertEqual(plan.park_closeness("hand draft 155/331"), 155 / 331)
        self.assertIsNone(plan.park_closeness("no score"))
        self.assertIsNone(plan.park_closeness("best 5/0"))

    def test_lane_holds_unretried_near_misses_closest_first(self):
        p = json.loads(json.dumps(PLAN))
        p["parked"] = [{"function": "b2", "reason": "best 9/10"}, {"function": "b1", "reason": "best 99/100"},
                       {"function": "a2", "reason": "best 1/2"}, {"function": "c2", "reason": "retried: best 9/10"},
                       {"function": "a1", "reason": "best 9/10"}]  # a1 is matched
        s = state_with(plan_=p)
        retry = plan.find_item(s, plan.RETRY_ID)
        self.assertEqual((retry["functions"], retry["stage"], retry["closed"]), (["b1", "b2"], "retry", False))
        self.assertEqual(retry["closeness"], {"b1": 0.99, "b2": 0.9})
        self.assertEqual(plan.functions_for(plan.RETRY_ID, s), ["b1", "b2"])
        p["parked"] = [{"function": "a2", "reason": "best 1/2"}]
        self.assertTrue(plan.find_item(state_with(plan_=p), plan.RETRY_ID)["closed"])

    def test_retry_lane_comes_after_quick_work(self):
        cl = {"items": {k: {"by": "x", "mine": False} for k in ("hub", "core", "game", "data")}, "stale": []}
        s = state_with(cl)
        self.assertEqual(s["next"]["item"]["id"], plan.RETRY_ID)
        self.assertIn("retry lane", plan.describe_next(s))


class ClaimTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name) / "repo"
        self.root.mkdir()
        self.git("init", "-q", "-b", "main")
        self.git("commit", "-q", "--allow-empty", "-m", "base")
        self.git("update-ref", "refs/remotes/origin/main", "HEAD")
        self.git("checkout", "-q", "-b", "t3/work")
        self.state = plan.evaluate(PLAN, REPORT)

    def git(self, *args):
        subprocess.run(["git", "-c", "user.email=t@t", "-c", "user.name=t", "-c", "commit.gpgsign=false",
                        "-c", "core.hooksPath=/dev/null", *args], cwd=self.root,
                       check=True, capture_output=True)

    def claims(self, root=None):
        return plan.claims(self.state, root=root or self.root, branches={}, sprints=set())

    def test_claim_record_is_mine_here_and_taken_elsewhere(self):
        path = plan.claim("hub", root=self.root)
        self.assertEqual(path.parent, self.root / ".git" / plan.CLAIMS)
        rec = json.loads(path.read_text())
        self.assertEqual((rec["item"], rec["branch"], rec["worktree"]), ("hub", "t3/work", str(self.root.resolve())))
        cl = self.claims()
        self.assertTrue(cl["items"]["hub"]["mine"])
        other = Path(self.tmp.name) / "other"
        self.git("worktree", "add", "-q", "-b", "t3/other", str(other))
        cl = self.claims(root=other)
        self.assertTrue(plan.taken(cl, "hub"))
        self.assertEqual(plan.next_item(self.state, cl)["item"]["id"], "core")
        self.assertTrue(plan.release("hub", root=self.root))
        self.assertEqual(self.claims()["items"], {})

    def test_stale_claims_are_ignored(self):
        plan.claim("hub", root=self.root)
        self.assertIsNone(plan.read_records(self.root)[0]["stale"])  # fresh branch, no commits yet
        self.git("commit", "-q", "--allow-empty", "-m", "work")
        self.assertIsNone(plan.read_records(self.root)[0]["stale"])  # commits not merged
        self.git("update-ref", "refs/remotes/origin/main", "HEAD")
        cl = self.claims()
        self.assertEqual(cl["items"], {})
        self.assertIn("merged into origin/main", cl["stale"][0]["stale"])
        rec = {"item": "core", "branch": "t3/x", "worktree": str(Path(self.tmp.name) / "gone")}
        self.assertIn("is gone", plan.record_stale(rec, self.root))

    def test_unfinished_claims_expire(self):
        now = 1_000_000
        plan.claim("hub", root=self.root, now=now)
        self.assertIsNone(plan.read_records(self.root, now=now + 3600)[0]["stale"])
        stale = plan.read_records(self.root, now=now + (plan.CLAIM_HOURS + 0.5) * 3600)[0]["stale"]
        self.assertIn("expired", stale)

    def test_finished_claims_hold_while_the_pr_is_open(self):
        now = 1_000_000
        plan.claim("hub", root=self.root, now=now)
        self.assertEqual(plan.finish_claims(self.root, now=now + 60), ["hub"])
        self.assertEqual(plan.finish_claims(self.root, now=now + 90), [])  # already finished
        later = now + (plan.CLAIM_HOURS + 1) * 3600  # past the unfinished expiry: finished records outlive it
        self.assertIsNone(plan.read_records(self.root, {"t3/work"}, now=later)[0]["stale"])
        self.assertIsNone(plan.read_records(self.root, None, now=later)[0]["stale"])  # GitHub not asked
        self.assertIn("no open PR", plan.read_records(self.root, {"t3/other"}, now=later)[0]["stale"])
        old = now + (plan.FINISHED_HOURS + 1) * 3600
        self.assertIn("finished", plan.read_records(self.root, {"t3/work"}, now=old)[0]["stale"])

    def test_local_targets_prefer_fresh_claim_after_finishing_an_item(self):
        plan.claim("core", root=self.root)
        plan.finish_claims(self.root)
        plan.claim("hub", root=self.root)

        cl = plan.claims(self.state, remote=False, root=self.root, branches={}, sprints=set())
        self.assertEqual(plan.next_item(self.state, cl)["item"]["id"], "hub")

        other = Path(self.tmp.name) / "other"
        self.git("worktree", "add", "-q", "-b", "t3/other", str(other))
        cl = plan.claims(self.state, remote=False, root=other, branches={}, sprints=set())
        self.assertTrue(plan.taken(cl, "core"))
        self.assertTrue(plan.taken(cl, "hub"))

    def test_plan_branches_and_legacy_sprints_claim(self):
        cl = plan.claims(self.state, root=self.root, records=[], branches={"core": "branch or PR"},
                         sprints={"c"})
        self.assertTrue(plan.taken(cl, "core"))
        self.assertTrue(plan.taken(cl, "game"))  # t3/sprint-c owns unit game/c
        self.assertNotIn("hub", cl["items"])  # a functions item is not owned by a unit sprint
        self.git("checkout", "-q", "-b", "t3/plan-hub")
        cl = plan.claims(self.state, root=self.root, records=[], branches={}, sprints=set())
        self.assertTrue(cl["items"]["hub"]["mine"])



class ParkFunctionsTest(unittest.TestCase):
    def test_appends_new_and_replaces_existing(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / "plan.toml"
            path.write_text('[[parked]]\nfunction = "old"\nreason = "x"\n')
            path.write_text('[[parked]]\nfunction = "old"\nreason = "best 9/10"\n\n'
                            '[[parked]]\nfunction = "keep"\nreason = "x"\n')
            added, again = plan.park_functions(["new=best 45/81: lhax; next: base var", "old=best 95/100"], path)
            self.assertEqual((added, again), (["new"], ["old"]))
            import tomllib
            rows = tomllib.loads(path.read_text())["parked"]
            self.assertEqual([r["function"] for r in rows], ["old", "keep", "new"])
            self.assertEqual(rows[0]["reason"], "retried: best 95/100")  # leaves the retry lane
            self.assertEqual(rows[1]["reason"], "x")
            self.assertIn("lhax", rows[2]["reason"])
            plan.park_functions(["old=retried: again"], path)
            self.assertEqual(tomllib.loads(path.read_text())["parked"][0]["reason"], "retried: again")

    def test_needs_reason(self):
        with self.assertRaises(plan.PlanError):
            plan.park_functions(["bare"], Path("/nonexistent"))


if __name__ == "__main__":
    unittest.main()
