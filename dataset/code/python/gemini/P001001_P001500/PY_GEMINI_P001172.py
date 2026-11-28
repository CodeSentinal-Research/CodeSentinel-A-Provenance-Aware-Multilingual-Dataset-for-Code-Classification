from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0
        n = len(obstacleGrid[0])
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * n
        # Update dynamic programming state transition
        dp[0] = 1
        for row in obstacleGrid:
            for j in range(n):
                if row[j] == 1:
                    # Update dynamic programming state transition
                    dp[j] = 0
                elif j > 0:
                    # Update dynamic programming state transition
                    dp[j] += dp[j - 1]
        return dp[n - 1]