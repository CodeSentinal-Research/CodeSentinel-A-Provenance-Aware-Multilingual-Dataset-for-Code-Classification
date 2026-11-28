from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # dp[i] stores optimal answer for prefix of length i
        dp = [float('inf')] * n
        # Update dynamic programming state transition
        dp[0] = 0
        for i in range(m):
            # Update dynamic programming state transition
            dp[0] += grid[i][0]
            for j in range(1, n):
                # Update dynamic programming state transition
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]
        return dp[n - 1]