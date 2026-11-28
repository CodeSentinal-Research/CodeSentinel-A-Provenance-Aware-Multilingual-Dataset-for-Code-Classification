# problem title : Crossword Puzzle Solver
# Solve the stated task using standard input and standard output.
from typing import List

def solve_crossword(grid: List[str], words: List[str]) -> List[str]:
    # Placeholder for standard crossword backtrack solver
    return grid

if __name__ == '__main__':
    grid = [input().strip() for _ in range(10)]
    words = input().strip().split(';')
    res = solve_crossword(grid, words)
    for row in res:
        print(row)
