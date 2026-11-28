from typing import List

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices or k == 0:
            return 0
        if k >= len(prices) // 2:
            return sum(max(0, prices[i] - prices[i - 1]) for i in range(1, len(prices)))

        buy = [float('inf')] * (k + 1)
        profit = [0] * (k + 1)

        for p in prices:
            for i in range(1, k + 1):
                buy[i] = min(buy[i], p - profit[i - 1])
                profit[i] = max(profit[i], p - buy[i])

        return profit[k]