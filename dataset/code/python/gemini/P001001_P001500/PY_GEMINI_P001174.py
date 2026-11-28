from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = list(triangle[-1])
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                # Update dynamic programming state transition
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
        return dp[0]