"""verify_toolkit — in-container helpers so the reviewer can express PRECISE
behavioral checks (derived from the issue's REQUIREMENTS) compactly, instead of
hand-rolling a full bash/script repro for behaviours that are genuinely awkward to
exercise from the shell (a missing binary, a specific platform, multiline command
output, an exact warning string, an exception type).

Design contract:
  * STDLIB-ONLY. This file is injected into the instance's real image next to the
    check script and imported there; it must not need anything pip can't already give
    a bare CPython. (unittest.mock is stdlib.)
  * LEAK-SAFE. Checks are authored from the ISSUE's stated requirements — never from
    the hidden fail_to_pass tests (which are not in the working tree anyway). The
    toolkit has no access to grading data; it only runs what the caller wrote.
  * PARSEABLE. Every assertion prints exactly one line:
        CHECK::<name>::PASS|FAIL::<detail>
    and summary() prints   SUMMARY::<p>/<n> passed   so the harness parses results
    without depending on a test framework being importable in the image.

"harness computes global, model acts local": the model writes a few precise local
assertions; the deterministic runtime decides whether the whole set passed AND
(separately, in plan_scope) whether the scope backing them is complete.
"""
from __future__ import annotations

import sys
import os
import io
import contextlib
import importlib
from unittest import mock

# Per-run nonce injected by the harness (run_checks_in_container) via env. Every marker
# line carries it so the code-under-test's own stdout CANNOT forge a CHECK/SUMMARY line
# (it can't predict the nonce) — closes the marker-spoofing soundness hole.
_NONCE = os.environ.get("JARVIS_CHECK_NONCE", "")

__all__ = [
    "check", "Stub", "safe_call", "load", "capture_output",
    "expect_true", "expect_equals", "expect_no_raise", "expect_raises",
    "expect_warning", "expect_contains", "expect_not_contains",
    "mock_subprocess_run", "mock_platform", "missing_binary",
    "summary", "results",
]

# ── result recording ─────────────────────────────────────────────────────────
_RESULTS: "list[tuple[str, bool]]" = []


def _safe_str(x) -> str:
    try:
        return str(x)
    except Exception:
        return "<unprintable>"


def _clean(s) -> str:
    # strip the marker delimiter + newlines so a name/detail can't forge or split a line
    return _safe_str(s).replace("::", ":").replace("\n", " ").replace("\r", " ")


def _emit(name: str, ok: bool, detail: str = "") -> bool:
    ok = bool(ok)
    nm = _clean(name)[:120]
    _RESULTS.append((nm, ok))
    d = _clean(detail)[:400]
    # nonce-tagged, plain ASCII — robust through any image's stdout encoding, unspoofable
    print(f"CHECK::{_NONCE}::{nm}::{'PASS' if ok else 'FAIL'}::{d}", flush=True)
    return ok


def results() -> "list[tuple[str, bool]]":
    return list(_RESULTS)


def _recover_got_want(exc: "AssertionError") -> str:
    """A bare `assert got == want` yields an EMPTY AssertionError message, so the
    coder's fix feedback reads 'assertion failed:' with no expected value. Recover
    the comparison's two sides by re-evaluating the assert expression's operands in
    the frame where it failed (AST-parse the source line, eval LHS/RHS in that frame's
    globals+locals), and return 'expected <want>, got <got>'.

    FAIL-SOFT CONTRACT: this is best-effort introspection only. ANY miss — no
    traceback, unreadable source, non-equality assert, an operand that raises or has
    a side effect when re-evaluated, a multi-line/compound assert — returns "" and the
    caller falls back to today's bare line. It must NEVER raise (it runs inside the
    check's except handler, which guards a single check; a raise here would still be
    caught by check()'s outer handler, but we keep it clean regardless)."""
    try:
        import ast as _ast, linecache as _lc, traceback as _tb
        tb = exc.__traceback__
        if tb is None:
            return ""
        # deepest frame = where the assert actually failed (inside the check body)
        while tb.tb_next is not None:
            tb = tb.tb_next
        frame = tb.tb_frame
        lineno = tb.tb_lineno
        fname = frame.f_code.co_filename
        src = _lc.getline(fname, lineno)
        if not src.strip():
            return ""
        try:
            node = _ast.parse(src.strip(), mode="exec")
        except SyntaxError:
            # the assert may span lines / be dedented oddly — best-effort single line only
            return ""
        if not (node.body and isinstance(node.body[0], _ast.Assert)):
            return ""
        test = node.body[0].test
        # only a single == comparison is unambiguous (got == want). Anything else
        # (and / or / chained / != / membership) → fall back to the bare line.
        if not (isinstance(test, _ast.Compare)
                and len(test.ops) == 1 and isinstance(test.ops[0], _ast.Eq)):
            return ""
        left_node, right_node = test.left, test.comparators[0]
        g, l = frame.f_globals, frame.f_locals
        try:
            got = eval(compile(_ast.Expression(left_node), "<assert>", "eval"), g, l)
            want = eval(compile(_ast.Expression(right_node), "<assert>", "eval"), g, l)
        except Exception:
            return ""   # re-eval raised / side-effecting operand → don't risk wrong info
        try:
            return f"expected {want!r}, got {got!r}"
        except Exception:
            return ""
    except BaseException:
        return ""


def _failing_source_line(exc: "BaseException") -> str:
    """The SOURCE LINE that raised — the deepest traceback frame's text (e.g. the
    `res = mod.read_edition(rec, fmt)` that raised the TypeError). The coder's fix
    feedback then names the failing CALL, not just the exception class, so it can
    localize the ROOT CAUSE (cd9c4eb5: the 2-arg call that raised, not 'rewrite the
    parser'). FAIL-SOFT: any miss (no traceback / unreadable source) → "". Never raises
    (it runs inside check()'s except handler; a raise here would still be caught by the
    same handler's surrounding scope, but we keep it clean regardless)."""
    try:
        import linecache as _lc
        tb = exc.__traceback__
        if tb is None:
            return ""
        while tb.tb_next is not None:
            tb = tb.tb_next
        frame = tb.tb_frame
        src = _lc.getline(frame.f_code.co_filename, tb.tb_lineno).strip()
        return src
    except BaseException:
        return ""


@contextlib.contextmanager
def check(name: str):
    """Isolated check block — the PRIMARY pattern. Any exception (incl. AssertionError)
    inside is caught and recorded as ONE failed check, so a crash in one block can never
    abort the others (the bug that zeroed an entire check script). On clean exit → PASS.

        sysctl = load("ansible.module_utils.facts.sysctl")
        with check("no_crash_on_unparseable_line"):
            w = []
            mod = Stub(get_bin_path=lambda *a, **k: "/sbin/sysctl",
                       run_command=lambda *a, **k: (0, "a = b\\nBADLINE\\nc = d\\n", ""),
                       warn=lambda m: w.append(m))
            r = sysctl.get_sysctl(mod, ["hw"])           # must not raise
            assert any("Unable to split sysctl line" in x for x in w)
            assert r.get("a") == "b"                     # valid keys still parsed
    """
    try:
        yield
    except AssertionError as e:
        msg = str(e)
        if not msg.strip():
            # bare `assert got == want` → empty message; recover got/want so the
            # coder's feedback names the expected value (FAIL-SOFT: "" on any miss).
            recovered = _recover_got_want(e)
            _emit(name, False, f"assertion failed: {recovered}" if recovered
                  else "assertion failed: ")
        else:
            _emit(name, False, f"assertion failed: {msg}")
    except KeyboardInterrupt:
        raise   # never swallow an operator interrupt
    except BaseException as e:  # incl. SystemExit (argparse/module.fail_json) — isolate it,
        # otherwise a check that drives a CLI/exit path would abort the whole script.
        # Record the EXCEPTION (type + message) AND the offending SOURCE LINE (the call that
        # raised) so the coder's fix feedback localizes the ROOT CAUSE — the failing call,
        # not just the exception class (cd9c4eb5: the 2-arg call that raised the TypeError).
        _src = _failing_source_line(e)
        _emit(name, False, f"{type(e).__name__}: {e}"
              + (f" | at: {_src}" if _src else ""))
    else:
        _emit(name, True, "")


def summary() -> bool:
    """Print the machine-parseable summary; return True iff ≥1 check ran and all passed."""
    p = sum(1 for _, ok in _RESULTS if ok)
    n = len(_RESULTS)
    print(f"SUMMARY::{_NONCE}::{p}/{n} passed", flush=True)
    return n > 0 and p == n


# ── generic test double ───────────────────────────────────────────────────────
class Stub:
    """A configurable mock object — the thing that makes the awkward cases testable.

    Pass attributes/methods as kwargs; callables are wrapped so every call is recorded
    on `.calls` (list of (name, args, kwargs)). Lets the model fake a repo-specific
    collaborator (e.g. ansible's `module` with .get_bin_path/.run_command/.warn) in
    two lines instead of importing+constructing the real heavyweight object.

        warnings = []
        mod = Stub(get_bin_path=lambda *a, **k: "/sbin/sysctl",
                   run_command=lambda *a, **k: (0, "k = v\\nBADLINE\\n", ""),
                   warn=lambda m: warnings.append(m))
    """

    def __init__(self, **attrs):
        object.__setattr__(self, "calls", [])
        for k, v in attrs.items():
            object.__setattr__(self, k, self._wrap(k, v) if callable(v) else v)

    def _wrap(self, name, fn):
        calls = self.calls

        def _w(*a, **k):
            calls.append((name, a, k))
            return fn(*a, **k)
        return _w

    def calls_to(self, name):
        return [c for c in self.calls if c[0] == name]


# ── calling helpers ────────────────────────────────────────────────────────────
def safe_call(fn, *a, **k):
    """Call fn; return (ok, result, exception). ok is False iff it raised."""
    try:
        return True, fn(*a, **k), None
    except Exception as e:  # noqa: BLE001 — we WANT to capture any failure for assertion
        return False, None, e


def _is_circular_import_error(exc: BaseException) -> bool:
    """True if exc is the 'partially initialized module … most likely due to a
    circular import' family (ImportError or the AttributeError CPython raises when a
    sibling reads a not-yet-bound name during a circular load)."""
    msg = str(exc)
    return ("circular import" in msg
            or ("partially initialized module" in msg)
            or ("cannot import name" in msg and "partially initialized" in msg))


def _sibling_modules(dotted_path):
    """Best-effort list of dotted names of the OTHER .py modules in the target's
    parent package (e.g. for `qutebrowser.config.configtypes` → every other module
    under `qutebrowser.config`). Used to prime a circular partner first. Returns []
    on any failure (the parent isn't importable / has no file location) — fail-soft."""
    parts = dotted_path.split(".")
    if len(parts) < 2:
        return []
    parent_name = ".".join(parts[:-1])
    leaf = parts[-1]
    try:
        parent = importlib.import_module(parent_name)
        import os as _os
        sibs = []
        for d in getattr(parent, "__path__", []) or []:
            try:
                for fn in _os.listdir(d):
                    if (fn.endswith(".py") and not fn.startswith("_")
                            and fn[:-3] != leaf):
                        sibs.append(f"{parent_name}.{fn[:-3]}")
            except Exception:  # noqa: BLE001
                pass
        return sibs
    except Exception:  # noqa: BLE001 — parent not importable → no priming
        return []


def load(dotted_path: str):
    """Import a module from the patched tree by dotted path (the repo is on PYTHONPATH).

    LOAD-ONCE, REUSE (FIX ④ — the super(type,obj) reload artifact): if the module is
    ALREADY in sys.modules we return that SAME module object — we do NOT reload it.
    Each check script runs in a FRESH `python -B` subprocess (the container / bwrap
    backends), so the FIRST time `load(M)` (or a transitive import of M, or a second
    `load(M)` in the same check) puts M in sys.modules, that object already holds the
    PATCHED code loaded from /app — there is never stale prior-process code to refresh.
    The old `importlib.reload(M)` instead built a SECOND set of class identities for M;
    any object/subclass created from the FIRST identity (e.g. a sibling that did `class
    C(M.Base)` at its own load time, or an instance the check already built) then no
    longer matched the reloaded class, so `super(C, obj)` raised
    `super(type, obj): obj must be an instance or subtype of type` IN THE CHECK'S OWN
    SETUP — a pure REVIEW-machinery artifact that corrupted an already-correct pass
    (811093: it failed the patched tree and drove the coder to monkey-patch builtins /
    bypass super() chasing an unsatisfiable check). Returning the single live module
    object keeps ONE class identity, so super() resolves normally. (self_verify's
    signature-6 message exemption stays as belt-and-suspenders for any reload that still
    happens elsewhere; this removes the source.)

    Circular-import robust (FIX #1): some repos (e.g. qutebrowser's
    `qutebrowser.config.configtypes` ↔ `configdata.BaseType`) cannot be imported
    bare leaf-first — importing the leaf triggers a sibling (`configdata`) whose
    module body reads `configtypes.BaseType` while `configtypes` is still
    mid-initialization → `AttributeError: partially initialized module … (most
    likely due to a circular import)`. The cure is purely import-ORDER: prime the
    cycle by importing the SIBLING modules in the target's parent package FIRST
    (verified live in the qutebrowser image: importing `qutebrowser.config.config`
    or `…configdata` first, then the leaf, loads cleanly — note priming only the
    `qutebrowser.config` *package* is NOT enough, the sibling *modules* must run).

    Strategy: (1) prime ancestor PACKAGES outermost-first; (2) try the bare import;
    (3) only on a circular-import error, drop any partially-initialized entries this
    attempt left in sys.modules, prime each sibling module of the parent package,
    then retry. FAIL-SOFT throughout: every priming step swallows its own failure,
    and the final attempt is the SAME bare import the old code did — so load() can
    never become worse than before and its return / raise contract is unchanged."""
    if dotted_path in sys.modules:
        # REUSE the already-live module (do NOT reload — see the load-once rationale
        # above). A None entry (a failed prior import left a sentinel) is dropped so the
        # real import below runs fresh.
        existing = sys.modules.get(dotted_path)
        if existing is not None:
            return existing
        sys.modules.pop(dotted_path, None)

    parts = dotted_path.split(".")
    # (1) Prime ancestor PACKAGES outermost-first (qutebrowser, qutebrowser.config, …)
    # so a leaf module at least sees its package context. Best-effort.
    for i in range(1, len(parts)):
        ancestor = ".".join(parts[:i])
        if ancestor in sys.modules:
            continue
        try:
            importlib.import_module(ancestor)
        except Exception:  # noqa: BLE001 — fail-soft: ancestors are only a priming hint
            pass

    try:
        return importlib.import_module(dotted_path)
    except (ImportError, AttributeError) as e:
        if not _is_circular_import_error(e):
            raise
        # A failed circular import can leave the target (and its partner) half-built
        # in sys.modules; those poisoned entries would make the retry a no-op or
        # re-raise. Drop the target so the retry re-runs its body fresh.
        sys.modules.pop(dotted_path, None)
        # (3) Prime the SIBLING modules of the parent package first (the proven cure),
        # then retry. Each prime is best-effort; a sibling that itself fails to import
        # is skipped (and its poisoned entry dropped so it can't break the leaf).
        for sib in _sibling_modules(dotted_path):
            if sib in sys.modules:
                continue
            try:
                importlib.import_module(sib)
            except Exception:  # noqa: BLE001 — fail-soft priming
                sys.modules.pop(sib, None)
        # Final attempt; if it still raises, it propagates exactly as a bare import
        # would have (the original contract — load() is never worse than before).
        return importlib.import_module(dotted_path)


@contextlib.contextmanager
def capture_output():
    """Capture stdout+stderr produced during the block: `with capture_output() as buf:`."""
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf), contextlib.redirect_stderr(buf):
        yield buf


# ── assertions (each prints one CHECK:: line) ──────────────────────────────────
# every expect_* is defensive: a bad arg / weird __eq__ / non-iterable records a FAILED
# check, it never propagates (a raise here would abort the whole script before summary()).
def expect_true(name, cond, detail="") -> bool:
    return _emit(name, bool(cond), detail or f"cond={cond!r}")


def expect_equals(name, got, want) -> bool:
    try:
        ok = (got == want)
    except Exception as e:  # noqa: BLE001
        return _emit(name, False, f"== raised {type(e).__name__}: {e}")
    return _emit(name, ok, f"got={got!r} want={want!r}")


def expect_no_raise(name, fn, *a, **k) -> bool:
    ok, _res, exc = safe_call(fn, *a, **k)
    return _emit(name, ok, "" if ok else f"raised {type(exc).__name__}: {exc}")


def expect_raises(name, exc_type, fn, *a, **k) -> bool:
    if not (isinstance(exc_type, type) and issubclass(exc_type, BaseException)):
        return _emit(name, False, f"bad exc_type {exc_type!r} (must be an Exception class)")
    ok, _res, exc = safe_call(fn, *a, **k)
    if ok:
        return _emit(name, False, f"did NOT raise (expected {exc_type.__name__})")
    return _emit(name, isinstance(exc, exc_type),
                 f"raised {type(exc).__name__}, expected {exc_type.__name__}")


def expect_warning(name, warnings, substr) -> bool:
    try:
        items = list(warnings or [])
    except TypeError:
        return _emit(name, False, f"warnings arg not iterable: {warnings!r}")
    hit = any(_safe_str(substr) in _safe_str(w) for w in items)
    return _emit(name, hit, f"want {substr!r} in {[_safe_str(w)[:80] for w in items[:3]]}")


def expect_contains(name, container, item) -> bool:
    try:
        ok = item in container
    except Exception:  # noqa: BLE001 — any broken __contains__ → FAIL, not a crash
        ok = False
    return _emit(name, ok, f"{item!r} in {_safe_str(container)[:120]}")


def expect_not_contains(name, container, item) -> bool:
    try:
        ok = item not in container
    except Exception:  # noqa: BLE001
        ok = True
    return _emit(name, ok, f"{item!r} NOT in {_safe_str(container)[:120]}")


# ── environment mocks (for behaviours that depend on the OS / external commands) ─
def mock_subprocess_run(handler):
    """Patch subprocess.run so code that shells out is driven by `handler(cmd)->result`.

    `handler` receives the cmd (list/str) and returns either a CompletedProcess-like
    object or a (returncode, stdout, stderr) tuple, which is wrapped. Use as a context
    manager. For code that uses module.run_command (ansible), prefer a Stub instead."""
    import subprocess

    class _CP:
        def __init__(self, rc, out, err):
            self.returncode, self.stdout, self.stderr = rc, out, err

    def _fake(cmd, *a, **k):
        r = handler(cmd)
        if isinstance(r, tuple):
            return _CP(*r)
        return r
    return mock.patch.object(subprocess, "run", side_effect=_fake)


def mock_platform(system: str):
    """Patch platform.system() and sys.platform to simulate an OS (e.g. 'OpenBSD')."""
    import platform
    plat = {"openbsd": "openbsd5", "linux": "linux", "darwin": "darwin",
            "freebsd": "freebsd11", "windows": "win32"}.get(system.lower(), system.lower())
    return _MultiPatch([
        mock.patch.object(platform, "system", return_value=system),
        mock.patch.object(sys, "platform", plat),
    ])


def missing_binary(name: str):
    """Make a get_bin_path / shutil.which / subprocess lookup for `name` fail as if the
    binary were absent — so 'binary missing -> ValueError/raises' paths can be tested."""
    import shutil

    real_which = shutil.which

    def _which(cmd, *a, **k):
        base = cmd.split("/")[-1] if isinstance(cmd, str) else cmd
        return None if base == name else real_which(cmd, *a, **k)
    return mock.patch.object(shutil, "which", side_effect=_which)


class _MultiPatch:
    """Enter/exit several patchers as one context manager."""
    def __init__(self, patchers):
        self._patchers = patchers

    def __enter__(self):
        return [p.__enter__() for p in self._patchers]

    def __exit__(self, *exc):
        for p in reversed(self._patchers):
            p.__exit__(*exc)
        return False
