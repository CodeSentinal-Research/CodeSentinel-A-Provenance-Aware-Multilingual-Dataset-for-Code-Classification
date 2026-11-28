# problem title : Sudoku Solver
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def is_valid(r: int, c: int, ch: str) -> bool:
            for i in range(9):
                if board[r][i] == ch or board[i][c] == ch:
                    return False
                if board[3 * (r // 3) + i // 3][3 * (c // 3) + i % 3] == ch:
                    return False
            return True

        def solve() -> bool:
            for r in range(9):
                for c in range(9):
                    if board[r][c] == '.':
                        for ch in "123456789":
                            if is_valid(r, c, ch):
                                board[r][c] = ch
                                if solve():
                                    return True
                                board[r][c] = '.'
                        return False
            return True

        solve()
