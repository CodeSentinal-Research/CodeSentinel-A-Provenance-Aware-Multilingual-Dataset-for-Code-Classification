# problem title : Knight Probability in Chessboard
# Solve the stated task using standard input and standard output.
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dp = [[0.0] * n for _ in range(n)]
        dp[row][column] = 1.0

        dirs = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

        for _ in range(k):
            new_dp = [[0.0] * n for _ in range(n)]
            for r in range(n):
                for c in range(n):
                    if dp[r][c] > 0:
                        for dr, dc in dirs:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < n and 0 <= nc < n:
                                new_dp[nr][nc] += dp[r][c] / 8.0
            dp = new_dp

        return sum(sum(row) for row in dp)
