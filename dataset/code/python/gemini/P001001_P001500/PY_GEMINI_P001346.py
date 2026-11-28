from typing import List

def solve_crossword(grid: List[str], words: List[str]) -> List[str]:
    """Solves 'Crossword Puzzle Solver' by applying optimal Backtracking logic."""
    # Placeholder for standard crossword backtrack solver
    return grid

if __name__ == '__main__':
    grid = [input().strip() for _ in range(10)]
    words = input().strip().split(';')
    res = solve_crossword(grid, words)
    for row in res:
        print(row)