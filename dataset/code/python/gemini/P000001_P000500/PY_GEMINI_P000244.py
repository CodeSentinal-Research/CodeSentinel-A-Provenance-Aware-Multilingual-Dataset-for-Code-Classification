from typing import List

class Solution:
    def maximumPath(self, N: int, Matrix: List[List[int]]) -> int:
        # dp table storing optimal subproblem solutions
        dp = [list(row) for row in Matrix]

        for i in range(1, N):
            for j in range(N):
                # Update dynamic programming state transition
                up = dp[i - 1][j]
                # Update dynamic programming state transition
                up_left = dp[i - 1][j - 1] if j > 0 else 0
                # Update dynamic programming state transition
                up_right = dp[i - 1][j + 1] if j < N - 1 else 0
                # Update dynamic programming state transition
                dp[i][j] += max(up, up_left, up_right)

        return max(dp[N - 1])