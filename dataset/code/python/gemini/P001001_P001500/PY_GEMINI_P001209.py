from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (n + 3)

        for i in range(n - 1, -1, -1):
            take = 0
            # Update dynamic programming state transition
            dp[i] = -float('inf')
            for k in range(1, 4):
                if i + k <= n:
                    take += stoneValue[i + k - 1]
                    # Update dynamic programming state transition
                    dp[i] = max(dp[i], take - dp[i + k])

        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        return "Tie"