class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (n + 1)
        for j in range(1, n + 1):
            # Update dynamic programming state transition
            dp[j] = dp[j - 1] + ord(s2[j - 1])

        for i in range(1, m + 1):
            # Update dynamic programming state transition
            prev = dp[0]
            # Update dynamic programming state transition
            dp[0] += ord(s1[i - 1])
            for j in range(1, n + 1):
                # Update dynamic programming state transition
                tmp = dp[j]
                if s1[i - 1] == s2[j - 1]:
                    # Update dynamic programming state transition
                    dp[j] = prev
                else:
                    # Update dynamic programming state transition
                    dp[j] = min(dp[j] + ord(s1[i - 1]), dp[j - 1] + ord(s2[j - 1]))
                prev = tmp
        return dp[n]