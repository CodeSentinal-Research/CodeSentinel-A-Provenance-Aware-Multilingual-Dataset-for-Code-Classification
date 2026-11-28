from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        n = len(s)
        # dp[i] stores optimal answer for prefix of length i
        dp = [False] * (n + 1)
        # Update dynamic programming state transition
        dp[0] = True

        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in words:
                    # Update dynamic programming state transition
                    dp[i] = True
                    break

        return dp[n]