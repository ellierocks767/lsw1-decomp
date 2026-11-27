# Plan revisions 5 to 15

Moved from [strategy](../strategy.md) at revision 16. Later revisions are noted there.

Revision 5 closes the executable `sdk-leftovers` work. Its former auto ranges
are now exact `Runtime/__start`, `Runtime/__init_fpu`, `dvd/dvdlow_test` and
`amcstubs/AmcExi2Stubs` units; existing split boundaries stay fixed. The two remaining
`.init` pseudo-functions contain only constants or alignment and are parked,
not counted as decompiled functions. See [SDK leftovers](sdk_import.md#sdk-leftovers).

Revision 7 (2026-11-11) records the first parallel day of item runs: #135 (`hvqm4`),
#136 (`rtl`), #137 (`nusound3`), #138 (`newlib`), #139 (`sn-tail`), #140
(`nungc-nufmv`) and #141 (`nudlist`) took main from 406,596 to 436,008 matched code
bytes and from 2,601 to 2,713 functions. Each run parked what it could not climb in its
PR; revision 7 moves those 76 plateaus into `[[parked]]` with their best scores and next
hypotheses, so `rtl`'s leftovers, `nusound3`, `nungc-nufmv` and `nudlist` stop counting
as open work. Stage 1 is left with hand-match work that has no donor: newlib's 12
functions, the three unattempted SN tail ranges and the two hub functions in `rtl`
(`fn_8006F28C`, `fn_8006F37C`, owned by `hubs`; its claim record outlived #128 because
the local branch was rebased, and goes with the next worktree cleanup). After that,
stage 2 continues at `ngc_mtl`. Donor-led runs (`hvqm4`, `newlib`)
matched the most bytes per hour, so look for a donor before climbing.

Stage 1 closed on 2026-11-12 without a revision: #145 (`newlib`, 11 functions), #146
(`sn-tail`, 26 functions; identified `__va_arg`, libsn `FSasync`/`sndvd` and `nan` in the
former pad range and promoted four units) and #147 (`rtl`, the two hub readers) took main
to 440,888 matched code bytes and 2,749 functions. Their plateaus are in `[[parked]]`.
Stage 2 runs `ngc_mtl` and `nutexanm` side by side. The CrashWOC GameCube decomp
(`src/nu3dx/*.c`, `src/system/gs/*.c` and its alpha NGC DWARF dump) is the main donor for
the Nu3d items: take algorithms, layouts and call order from it, not codegen.

Revision 8 (2026-11-12) adds no new item. `tools/plan.py` reported that stage `s2-nu3d` has no
recommendable item. Five of its items are still open (`nucamera`, `nuhgobj`, `nuportal`,
`nurndr-nugscn`, `nuanim`), and each is claimed by an in-flight worktree. Stage `s3-objects-ai`
therefore starts by look-ahead with `apiobject` while those runs finish. The unit has OpenSaga
leads by body, not only by name. `fn_8008F660` is `AISysFindRoute`, `fn_8008FB18` is
`QuickNewRayCast`, `fn_80090FB0` is `APIObjectCollisions`, `fn_80091FC0` is
`APICharacterSysInit` and `fn_800913BC` is an earlier and longer `AddAnimEffects`. This
revision also parks the `apiobject` plateaus with their best scores.

Revision 9 (2026-11-13) records the second `nuportal` pass: three new strict
matches / 3,908 B and four measured plateaus, each above the 25-candidate floor.
The item has no unattempted functions; promotion still needs the remaining bodies
and unit-wide section/relocation/range checks. The stale scaffold note is replaced
with the current result. The zero-yield `nuanim` bench warning was reviewed; this
pass supplies no evidence to reorder stages or reclassify its unfinished work.
Stage 2 keeps its existing order, continuing at the next unclaimed item.

Revision 10 (2026-11-25) records a single-thread `nurndr-nugscn` pass. `nustream`'s
fn_8002C644 gains a NonMatching source candidate (122/232, up from 107) and is parked;
the two `nuspecial` plateaus are re-climbed without gain and parked. The `nuanim` item's
four PR 166 plateaus move into `[[parked]]` with their best scores and next hypotheses.
The three `nurndr` functions stay in the item for the next pass; stage order is unchanged.

Revision 11 (2026-11-26) records the `nurndr` hillclimb. `fn_80024F68` matches all
270 instructions in the strict verifier (1,080 B), up from 222. It counts as a
strict-only match. The prior zero-yield pass parked the `nustream` and `nuspecial`
plateaus, and the new match supports continuing the renderer item with
`fn_80026F0C` and `fn_80026710`.

Revision 12 (2026-11-26) verifies `fn_80026F0C` (229/229 instructions, 916 B
added to objdiff, up from a 206/229 candidate). This result supports keeping
`nurndr-nugscn` in place after reviewing its prior zero-yield warning.
`fn_80026710` remains open for a separate C draft.

Revision 13 (2026-11-26) parks `fn_80026710`, the final open body in
`nurndr-nugscn`, after the typed draft reached 398/511 identical instructions.
After reviewing the zero-yield renderer runs, the plan advances to stage 3
(`s3-objects-ai`). The renderer draft still needs a strict match before it can
count toward code progress.

Revision 14 (2026-11-26) records an `aisys-1` look-ahead while the renderer item
was claimed. `fn_8007F130` matches all 137 instructions (548 B), and
`fn_8007E97C` remains with its existing claimant. The historical zero-yield
warnings for `nuanim` and `nurndr-nugscn` were reviewed. The `fn_8007F130` match supports
continuing the `aisys-1` item in stage 3.

Revision 15 (2026-11-26) parks `fn_8007E97C` (596 B), the last open body in
`aisys-1`, after the typed traversal reached 128/149 exact instructions. In
both script loops, the draft omits a register copy at each state and condition
list setup. The next pass can compare ProDG's register lifetimes at those
calls with the matching `AIPathNodeUpdatePos`. The planner can advance to
`aisys-2` while this function still needs a strict match.
