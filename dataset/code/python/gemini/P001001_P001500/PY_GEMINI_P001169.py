from typing import List

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        # dp[i] stores optimal answer for prefix of length i
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        # Update dynamic programming state transition
        dp[m][n - 1] = dp[m - 1][n] = 1

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # Update dynamic programming state transition
                min_req = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]
                # Update dynamic programming state transition
                dp[i][j] = max(1, min_req)

        return dp[0][0]