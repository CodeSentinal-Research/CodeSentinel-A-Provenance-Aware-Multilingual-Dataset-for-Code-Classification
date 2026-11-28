class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = list(range(n + 1))
        for i in range(1, m + 1):
            # Update dynamic programming state transition
            prev = dp[0]
            # Update dynamic programming state transition
            dp[0] = i
            for j in range(1, n + 1):
                # Update dynamic programming state transition
                tmp = dp[j]
                if word1[i - 1] == word2[j - 1]:
                    # Update dynamic programming state transition
                    dp[j] = prev
                else:
                    # Update dynamic programming state transition
                    dp[j] = 1 + min(prev, dp[j], dp[j - 1])
                prev = tmp
        return dp[n]