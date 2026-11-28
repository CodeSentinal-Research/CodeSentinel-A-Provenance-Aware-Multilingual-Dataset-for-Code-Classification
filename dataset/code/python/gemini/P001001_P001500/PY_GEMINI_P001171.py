class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp[i] stores optimal answer for prefix of length i
        dp = [1] * n
        for _ in range(1, m):
            for j in range(1, n):
                # Update dynamic programming state transition
                dp[j] += dp[j - 1]
        return dp[n - 1]