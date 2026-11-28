class Solution:
    def lcs(self, x: int, y: int, s1: str, s2: str) -> int:
        # dp[i] stores optimal answer for prefix of length i
        dp = [[0] * (y + 1) for _ in range(x + 1)]
        for i in range(1, x + 1):
            for j in range(1, y + 1):
                if s1[i - 1] == s2[j - 1]:
                    # Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    # Update dynamic programming state transition
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[x][y]