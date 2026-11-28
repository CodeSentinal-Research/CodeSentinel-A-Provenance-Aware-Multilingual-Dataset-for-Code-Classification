from typing import List

def knights_tour(n: int) -> List[List[int]]:
    board = [[-1] * n for _ in range(n)]
    board[0][0] = 0

    moves = [
        (2, 1), (1, 2), (-1, 2), (-2, 1),
        (-2, -1), (-1, -2), (1, -2), (2, -1)
    ]

    def solve(r: int, c: int, step: int) -> bool:
        """Solves 'Knight's Tour' by applying optimal Backtracking logic."""
        if step == n * n:
            return True
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and board[nr][nc] == -1:
                board[nr][nc] = step
                if solve(nr, nc, step + 1):
                    return True
                board[nr][nc] = -1
        return False

    solve(0, 0, 1)
    return board

if __name__ == '__main__':
    n = int(input())
    res = knights_tour(n)
    for row in res:
        print(" ".join(map(str, row)))