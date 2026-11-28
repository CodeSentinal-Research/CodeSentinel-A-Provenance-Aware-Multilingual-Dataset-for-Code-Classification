"""Benchmark — "complex reasoning algorithm problem": expression evaluator.

Implement `calculate(s)` for `+ - * /` with parentheses and unary minus;
integer division truncates toward zero (Basic-Calculator-III level). The agent
writes solution.py and self-improves it through test-failure feedback.
Deterministic scoring: N test cases -> N pass/fail for the paired gate.
"""
from __future__ import annotations

import json
import os
from pathlib import Path
import re
import subprocess
import sys

from .artifacts import (
    read_artifact_bytes,
    read_artifact_text,
    require_regular_artifact,
)
from .gym import EpisodeResult, EpisodeSpec, GymAdapter, RewardBreakdown
from .llm import ChatClient
from .process_env import sanitized_child_environment
from .rsi import Benchmark

PROBLEM = """# Expression Evaluator

Implement a function in `solution.py`:

    def calculate(s: str) -> int

`s` is a valid arithmetic expression made of:
  - non-negative integers
  - the operators  +  -  *  /
  - parentheses  (  )
  - spaces (ignore them)

Rules:
  - `*` and `/` bind tighter than `+` and `-`.
  - `/` is integer division that **truncates toward zero** (e.g. 3/2 = 1, -3/2 = -1).
  - Unary minus is allowed: `-1`, `-(3+4)`, `1 - ( -2 )` are all valid.
  - Intermediate and final results fit in a 32-bit signed integer.

Run `python3 test_runner.py` to check your work.
"""

TASK_PROMPT = (
    "Implement `calculate(s)` in solution.py to solve the problem in problem.md. "
    "Run `python3 test_runner.py` to check; iterate until all tests pass. "
    "Leave your final implementation in solution.py."
)

SOLUTION_STUB = '''def calculate(s: str) -> int:
    """Evaluate + - * / with parentheses and unary minus (truncating division)."""
    raise NotImplementedError
'''

TEST_RUNNER = '''import json
import sys

sys.path.insert(0, ".")

try:
    from solution import calculate
except Exception as e:
    print("IMPORT_ERROR:", type(e).__name__, e)
    sys.exit(1)

with open("tests.json", "r", encoding="utf-8") as f:
    tests = json.load(f)

for t in tests:
    try:
        got = calculate(t["input"])
        ok = got == t["expected"]
        print(f"{t['id']}: {'PASS' if ok else 'FAIL'} got={got} expected={t['expected']}")
    except Exception as e:
        print(f"{t['id']}: ERROR {type(e).__name__}: {e}")
'''

# Public smoke cases (id, expression, expected), verified by hand.
PUBLIC_ALGO_CASES = [
    {"id": "c01", "input": "1 + 1", "expected": 2},
    {"id": "c02", "input": " 6-4 / 2 ", "expected": 4},
    {"id": "c03", "input": "3+2*2", "expected": 7},
    {"id": "c04", "input": " 3/2 ", "expected": 1},
    {"id": "c05", "input": " 3+5 / 2 ", "expected": 5},
    {"id": "c06", "input": "2*(5+5*2)/3+(6/2+8)", "expected": 21},
    {"id": "c07", "input": "(2+6*3+5-(3*14/7+2)*5)+3", "expected": -12},
    {"id": "c08", "input": "-1+1", "expected": 0},
    {"id": "c09", "input": "-(3+4)", "expected": -7},
    {"id": "c10", "input": "1 - ( -2 )", "expected": 3},
    {"id": "c11", "input": "(0)", "expected": 0},
    {"id": "c12", "input": " 2 * (3 + 4) ", "expected": 14},
    {"id": "c13", "input": "-(2+3*4)", "expected": -14},
    {"id": "c14", "input": "7-8/4", "expected": 5},
    {"id": "c15", "input": "14/3*2", "expected": 8},
    {"id": "c16", "input": "0", "expected": 0},
    {"id": "c17", "input": "-3/2", "expected": -1},
    {"id": "c18", "input": "7/-3", "expected": -2},
]
TEST_CASES = PUBLIC_ALGO_CASES

def evaluate_algo_candidate(
    candidate_root: str, timeout: float = 2.0
) -> tuple[bool, ...]:
    """Narrow lazy bridge for explicit in-process referee tests."""
    from .sealed_algorithm_evaluator import evaluate_algo_candidate as evaluate

    return evaluate(candidate_root, timeout=timeout)

PUBLIC_TEST_RUNNER = TEST_RUNNER.replace('"tests.json"', '"public_tests.json"')


def _write(path, content):
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)


class AlgoGymAdapter:
    """Public expression cases; expected values remain in deterministic code."""

    name = "algo-public"
    suite_id = "algo-public-v1"
    reward_spec_version = "1"

    def __init__(self):
        self._cases = tuple(dict(case) for case in PUBLIC_ALGO_CASES)
        self._by_id = {case["id"]: case for case in self._cases}

    def episodes(self) -> tuple[EpisodeSpec, ...]:
        return tuple(
            EpisodeSpec(
                episode_id=f"public-{case['id']}",
                task=TASK_PROMPT,
                seed=index,
            )
            for index, case in enumerate(self._cases)
        )

    def _case(self, spec: EpisodeSpec) -> dict:
        return self._by_id[spec.episode_id.removeprefix("public-")]

    def setup_workspace(self, candidate_root, spec, workspace) -> None:
        case = self._case(spec)
        Path(workspace, "problem.md").write_text(PROBLEM, encoding="utf-8")
        Path(workspace, "public_tests.json").write_text(
            json.dumps([case], indent=2, ensure_ascii=False), encoding="utf-8"
        )
        Path(workspace, "test_runner.py").write_text(
            PUBLIC_TEST_RUNNER, encoding="utf-8"
        )
        Path(workspace, "solution.py").write_bytes(
            read_artifact_bytes(candidate_root, "solution.py")
        )

    def score(self, workspace, spec, final_text, transcript) -> RewardBreakdown:
        case = self._case(spec)
        script = (
            "import json\n"
            "from solution import calculate\n"
            f"print(json.dumps({{'value': calculate({case['input']!r})}}))\n"
        )
        diagnostics = ()
        passed = False
        try:
            process = subprocess.run(
                [sys.executable, "-c", script],
                cwd=workspace,
                capture_output=True,
                text=True,
                timeout=10,
                env=sanitized_child_environment(),
            )
            if process.returncode != 0:
                diagnostics = ("public_case_error",)
            else:
                lines = process.stdout.splitlines()
                payload = json.loads(lines[-1]) if lines else {}
                passed = payload.get("value") == case["expected"]
                if not passed:
                    diagnostics = ("public_case_incorrect",)
        except subprocess.TimeoutExpired:
            diagnostics = ("public_case_timeout",)
        except (json.JSONDecodeError, KeyError, TypeError, ValueError):
            diagnostics = ("public_case_error",)
        return RewardBreakdown.from_mapping(
            {"public_case_correct": 1.0 if passed else 0.0}, diagnostics
        )


ALGO_COACH_INSTRUCTION = """You are the coach for a public algorithm practice Gym.
Use only the public episode results and deterministic diagnostics below. Return
the complete corrected solution.py implementation. Return only Python code."""


_FENCE_LINE = re.compile(r"^[ \t]*```(?:[ \t]*([A-Za-z0-9_.+-]+))?[ \t]*$")


def _strip_markdown_fence(content: str) -> str | None:
    """Extract one complete fenced block, rejecting malformed or ambiguous text."""
    stripped = content.strip()
    if "```" not in stripped:
        return stripped

    lines = stripped.splitlines()
    blocks: list[str] = []
    index = 0
    while index < len(lines):
        line = lines[index]
        if "```" not in line:
            index += 1
            continue
        if _FENCE_LINE.fullmatch(line) is None:
            return None

        index += 1
        body: list[str] = []
        while index < len(lines) and lines[index].strip() != "```":
            if "```" in lines[index]:
                return None
            body.append(lines[index])
            index += 1
        if index >= len(lines):
            return None

        block = "\n".join(body).strip()
        if not block:
            return None
        blocks.append(block)
        if len(blocks) > 1:
            return None
        index += 1

    return blocks[0] if len(blocks) == 1 else None


class AlgoBenchmark(Benchmark):
    name = "algo"
    artifact_name = "solution.py"
    suite_id = "algo-sealed-v1"
    gym_adapter: GymAdapter = AlgoGymAdapter()

    def __init__(self):
        self.cases = TEST_CASES

    def ensure_artifact(self, root: str) -> None:
        artifact = Path(root, self.artifact_name)
        try:
            os.lstat(artifact)
        except FileNotFoundError:
            flags = os.O_WRONLY | os.O_CREAT | os.O_EXCL | getattr(os, "O_NOFOLLOW", 0)
            descriptor = os.open(artifact, flags, 0o644)
            with os.fdopen(descriptor, "w", encoding="utf-8") as output:
                output.write(SOLUTION_STUB)
                output.flush()
                os.fsync(output.fileno())
            require_regular_artifact(root, self.artifact_name)
            return
        require_regular_artifact(root, self.artifact_name)

    def propose(
        self,
        chat_client: ChatClient,
        candidate_root: str,
        episodes: tuple[EpisodeResult, ...],
    ) -> str | None:
        valid = [episode for episode in episodes if episode.valid]
        if not valid:
            return None
        public_feedback = [
            {
                "episode_id": episode.episode_id,
                "reward": episode.reward.total,
                "components": dict(episode.reward.components),
                "diagnostics": list(episode.reward.diagnostics),
                "final_text": episode.final_text,
            }
            for episode in valid
            if episode.reward is not None
        ]
        if not public_feedback:
            return None
        current = read_artifact_text(candidate_root, self.artifact_name)
        prompt = (
            ALGO_COACH_INSTRUCTION
            + "\n\nPUBLIC_PROBLEM:\n"
            + PROBLEM
            + "\n\nCURRENT_SOLUTION:\n"
            + current
            + "\n\nPUBLIC_GYM_RESULTS:\n"
            + json.dumps(public_feedback, ensure_ascii=False)
        )
        message = chat_client.chat(
            [{"role": "user", "content": prompt}], max_tokens=4096
        )
        content = _strip_markdown_fence(message.get("content") or "")
        return content or None

    def setup(self, agent):
        root = agent.state.root
        _write(os.path.join(root, "problem.md"), PROBLEM)
        _write(os.path.join(root, "tests.json"),
               json.dumps(self.cases, indent=2, ensure_ascii=False))
        _write(os.path.join(root, "test_runner.py"), TEST_RUNNER)
        self.ensure_artifact(root)

    def _run_tests(self, root):
        require_regular_artifact(root, self.artifact_name)
        p = subprocess.run(
            ["python3", "test_runner.py"], cwd=root,
            capture_output=True, text=True, timeout=120,
            env=sanitized_child_environment(),
        )
        lines = (p.stdout or "").splitlines()
        results = []
        for case in self.cases:
            line = next((ln for ln in lines if ln.startswith(case["id"] + ":")), None)
            results.append(line is not None and "PASS" in line)
        return results, lines

    def evaluate(self, agent):
        agent.workspace = agent.state.root
        agent.run(TASK_PROMPT)
        results, _ = self._run_tests(agent.state.root)
        return results

    def reflect(self, agent, results):
        failing_idx = [i for i, ok in enumerate(results) if not ok]
        if not failing_idx:
            return None
        solution = read_artifact_text(agent.state.root, self.artifact_name)
        _, lines = self._run_tests(agent.state.root)
        fail_lines = [
            next((ln for ln in lines if ln.startswith(self.cases[i]["id"] + ":")), "")
            for i in failing_idx
        ]
        prompt = (
            "You are improving your own solution.py against failing tests.\n\n"
            f"PROBLEM:\n{PROBLEM}\n\n"
            f"CURRENT solution.py:\n{solution}\n\n"
            "FAILING TEST CASES (id: FAIL got=X expected=Y):\n"
            + "\n".join(fail_lines)
            + "\n\n"
            "Diagnose the bug(s) and return the FULL corrected solution.py. "
            "Return ONLY the Python code, nothing else."
        )
        msg = agent.llm.chat(
            [{"role": "user", "content": prompt}], max_tokens=4096
        )
        return (msg.get("content") or "").strip() or None

    def apply(self, agent, content):
        _write(os.path.join(agent.state.root, "solution.py"), content)
