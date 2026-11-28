#!/usr/bin/env python3
"""Interactive quizmaster for the n-queens puzzle.

The script leads students through the explosion from "choose any squares" combinations,
down to row/column permutations, and finally to diagonal-safe n-queens solutions.
Run `python quizmaster_nqueens.py [n]` to play or `python quizmaster_nqueens.py --test`
for quick self-checks.
"""
from __future__ import annotations

import math
import sys
import time
from typing import Callable, Iterable


def format_int(value: int) -> str:
    """Return the integer formatted with underscores for readability."""
    return f"{value:_}"


def safe_int_input(prompt: str) -> int:
    """Prompt for an integer between 1 and 15 inclusive."""
    while True:
        try:
            raw = input(prompt).strip()
        except EOFError:
            print("\nThe quizmaster cannot read silence forever. Farewell!")
            sys.exit(0)
        if not raw:
            print("Empty input? Try a number between 1 and 15.")
            continue
        try:
            value = int(raw)
        except ValueError:
            print("That is not an integer. Dust off those digits and try again.")
            continue
        if 1 <= value <= 15:
            return value
        print("Out of range. Please choose a number from 1 to 15.")


def read_guess(prompt: str) -> int:
    """Prompt until a valid integer is entered; used for quiz answers."""
    while True:
        try:
            raw = input(prompt).strip()
        except EOFError:
            print("\nAbrupt silence! Quiz adjourned.")
            sys.exit(0)
        if not raw:
            print("No answer? Give me an integer to chew on.")
            continue
        try:
            return int(raw)
        except ValueError:
            print("Numbers only, brave solver. Try again.")


def count_nqueens(n: int, return_nodes: bool = False) -> int | tuple[int, int]:
    """Count non-attacking n-queens solutions using bitmask backtracking."""
    mask = (1 << n) - 1
    total = 0
    nodes_visited = 0

    def backtrack(row: int, columns: int, diag1: int, diag2: int) -> None:
        nonlocal total, nodes_visited
        if row == n:
            total += 1
            return
        available = ~(columns | diag1 | diag2) & mask
        while available:
            bit = available & -available
            available ^= bit
            nodes_visited += 1
            backtrack(
                row + 1,
                columns | bit,
                (diag1 | bit) << 1 & mask,
                (diag2 | bit) >> 1,
            )

    backtrack(0, 0, 0, 0)
    if return_nodes:
        return total, nodes_visited
    return total


def solve_with_stats(n: int) -> tuple[int, int, float]:
    """Return solution count, visited board positions, and solve duration in seconds."""
    start = time.perf_counter()
    solutions, visited = count_nqueens(n, return_nodes=True)
    elapsed = time.perf_counter() - start
    return solutions, visited, elapsed


def format_duration(seconds: float) -> str:
    """Format elapsed seconds with three decimal places."""
    return f"{seconds:.3f} seconds"


def run_self_checks() -> None:
    """Lightweight assertions for known n-queens counts."""
    known_counts = {
        1: 1,
        2: 0,
        3: 0,
        4: 2,
        5: 10,
        6: 4,
        7: 40,
        8: 92,
    }
    for size, expected in known_counts.items():
        actual = count_nqueens(size)
        assert (
            actual == expected
        ), f"n={size}: expected {expected}, got {actual}"
    print("Self-checks passed. Queens salute you!")


def handle_first_question(n: int, placement_count: int) -> bool:
    """Conduct the board-positions question, returning True if answered correctly."""
    print(
        f"Do you know what is coming for you? I think... you... DO NOT! So answer me first: "
        f"How many possible board positions are there for placing {format_int(n)} queens on the board?"
    )
    success = False
    hints: Iterable[str] = (
        "Hint: Think of choosing distinct squares out of the entire board...",
        "Hint: It's the number of ways to choose n squares from n x n total squares.",
    )
    hint_iter = iter(hints)
    attempts = 0
    while attempts < 3:
        guess = read_guess("Your guess: ")
        attempts += 1
        if guess == placement_count:
            print(
                "Yes, correct! This is indeed the right answer... very nice. - But can you also guess the number of solutions?"
            )
            success = True
            break
        if attempts < 3:
            try:
                hint = next(hint_iter)
            except StopIteration:
                hint = "No more hints - just pure combinatorial counting!"
            print(f"Not quite. {hint}")
    if not success and attempts >= 3:
        print(
            f"Answer reveal: Total board positions = (n^2 choose n) = {format_int(placement_count)}."
        )
        print("Combinations got the upper hand this time. Shake it off and face the diagonals!")
    return success


def handle_second_question(
    n: int,
    placement_count: int,
    solution_count: int,
    solver: Callable[[], tuple[int, int, float]],
) -> None:
    """Conduct the non-attacking solutions question."""
    print("Now, how many non-attacking n-queens board arrangements exist?")
    attempts = 0
    while attempts < 3:
        guess = read_guess("Your guess: ")
        attempts += 1
        if guess == solution_count:
            print(
                f"Royal approval: {format_int(solution_count)} formations survive the diagonal gauntlet!"
            )
            return
        if attempts == 1:
            print(
                f"A bold guess, but diagonals disagree. Bound: 0 <= solutions <= {format_int(placement_count)}."
            )
        elif attempts == 2:
            print(
                "Another miss. Fact: solutions = 0 for n in {2, 3}, solutions = 1 for n = 1, otherwise positive."
            )
    print("AH! You do not know... Well, I do not either, give me a second to calculate the solution...")
    print("*Quizmaster starts calculating*")
    computed_solutions, visited_positions, elapsed = solver()
    assert (
        computed_solutions == solution_count
    ), "Solver result diverged from precomputed solution count."
    print(
        "After thinking for {time_spent} and checking {positions} positions. "
        "I have come to the conclusion that the answer is {solutions}.".format(
            time_spent=format_duration(elapsed),
            positions=format_int(visited_positions),
            solutions=format_int(computed_solutions),
        )
    )
    print("Diagonals are merciless, but now you know their true strength.")


def wrap_up(n: int, solution_count: int) -> None:
    """Print the closing remark."""
    print(
        "Well, now we know the number solution for {n_val} queens is {solutions}.".format(
            n_val=format_int(n), solutions=format_int(solution_count)
        )
    )


def parse_n_argument(args: list[str]) -> int | None:
    """Extract optional numeric argument if present."""
    numeric_args = [arg for arg in args if arg != "--test"]
    if not numeric_args:
        return None
    if len(numeric_args) > 1:
        raise ValueError("Provide at most one n value.")
    raw = numeric_args[0]
    try:
        value = int(raw)
    except ValueError as exc:
        raise ValueError("n must be an integer.") from exc
    if not 1 <= value <= 15:
        raise ValueError("n must be between 1 and 15.")
    return value


def main() -> None:
    args = sys.argv[1:]
    if "--test" in args:
        run_self_checks()
        return

    try:
        n_value = parse_n_argument(args)
    except ValueError as error:
        print(f"Input error: {error}")
        sys.exit(1)

    if n_value is None:
        n_value = safe_int_input("Enter n (1-15): ")

    placement_count = math.comb(n_value * n_value, n_value)
    permutation_count = math.factorial(n_value)
    solution_count = count_nqueens(n_value)

    def compute_solver_stats() -> tuple[int, int, float]:
        return solve_with_stats(n_value)

    introduction = (
        "Welcome to the Royal Board, where chalk dust sketches diagonal duels! "
        "I'm your mischievous quizmaster, corralling queens and curious minds alike. "
        "The challenge: place n queens on an n by n board with no shared row, column, or diagonal. "
        "Sharpen that wit - the combinatorial pop quiz begins now."
    )
    print(introduction)

    handle_first_question(n_value, placement_count)
    handle_second_question(
        n_value,
        placement_count,
        solution_count,
        compute_solver_stats,
    )
    wrap_up(n_value, solution_count)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nQuiz cancelled by royal decree. Until next time!")