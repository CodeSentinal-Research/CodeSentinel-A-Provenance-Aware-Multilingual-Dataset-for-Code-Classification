from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = list(matrix[0])

        for i in range(1, n):
            new_dp = [0] * n
            for j in range(n):
                # Update dynamic programming state transition
                best = dp[j]
                if j > 0:
                    # Update dynamic programming state transition
                    best = min(best, dp[j - 1])
                if j < n - 1:
                    # Update dynamic programming state transition
                    best = min(best, dp[j + 1])
                # Update dynamic programming state transition
                new_dp[j] = matrix[i][j] + best
            dp = new_dp

        return min(dp)