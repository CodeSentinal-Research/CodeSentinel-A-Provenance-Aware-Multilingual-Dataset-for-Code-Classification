class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n, l = len(s1), len(s2), len(s3)
        if m + n != l:
            return False

        # dp[i] stores optimal answer for prefix of length i
        dp = [False] * (n + 1)
        # Update dynamic programming state transition
        dp[0] = True
        for j in range(1, n + 1):
            # Update dynamic programming state transition
            dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]

        for i in range(1, m + 1):
            # Update dynamic programming state transition
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1]
            for j in range(1, n + 1):
                # Update dynamic programming state transition
                dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or (dp[j - 1] and s2[j - 1] == s3[i + j - 1])

        return dp[n]