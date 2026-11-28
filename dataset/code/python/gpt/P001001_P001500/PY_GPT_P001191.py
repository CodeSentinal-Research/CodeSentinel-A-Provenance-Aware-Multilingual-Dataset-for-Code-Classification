# problem title : Best Time to Buy and Sell Stock with Transaction Fee
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        cash, hold = 0, -prices[0]
        for p in prices[1:]:
            cash = max(cash, hold + p - fee)
            hold = max(hold, cash - p)
        return cash
