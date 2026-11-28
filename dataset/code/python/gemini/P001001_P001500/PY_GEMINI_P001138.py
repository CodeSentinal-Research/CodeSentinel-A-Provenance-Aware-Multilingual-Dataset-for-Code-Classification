from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (amount + 1)
        # Update dynamic programming state transition
        dp[0] = 1
        for c in coins:
            for i in range(c, amount + 1):
                # Update dynamic programming state transition
                dp[i] += dp[i - c]
        return dp[amount]