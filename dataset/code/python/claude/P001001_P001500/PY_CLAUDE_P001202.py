
from typing import List

class Solution:
    def knapsack01(self, weights: List[int], values: List[int], W: int) -> int:
        dp = [0] * (W + 1)
        for i in range(len(weights)):
            for j in range(W, weights[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i])
        return dp[W]
