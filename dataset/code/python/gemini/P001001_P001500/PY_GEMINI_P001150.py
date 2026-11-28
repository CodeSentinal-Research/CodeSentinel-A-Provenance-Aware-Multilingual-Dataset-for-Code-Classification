class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            new_dp = [0] * n
            # Update dynamic programming state transition
            new_dp[i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    # Update dynamic programming state transition
                    new_dp[j] = dp[j - 1] + 2
                else:
                    # Update dynamic programming state transition
                    new_dp[j] = max(dp[j], new_dp[j - 1])
            dp = new_dp
        return dp[n - 1]