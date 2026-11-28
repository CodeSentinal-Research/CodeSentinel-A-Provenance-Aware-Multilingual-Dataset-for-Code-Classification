class Solution:
    def strangePrinter(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        # dp[i] stores optimal answer for prefix of length i
        dp = [[0] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            # Update dynamic programming state transition
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    # Update dynamic programming state transition
                    dp[i][j] = dp[i][j - 1]
                else:
                    dp[i][j] = min(dp[i][k] + dp[k + 1][j] for k in range(i, j))

        return dp[0][n - 1]