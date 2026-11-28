from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i] stores optimal answer for prefix of length i
        dp = [float('inf')] * (amount + 1)
        # Update dynamic programming state transition
        dp[0] = 0
        for c in coins:
            for i in range(c, amount + 1):
                # Update dynamic programming state transition
                dp[i] = min(dp[i], dp[i - c] + 1)
        # Update dynamic programming state transition
        return dp[amount] if dp[amount] != float('inf') else -1