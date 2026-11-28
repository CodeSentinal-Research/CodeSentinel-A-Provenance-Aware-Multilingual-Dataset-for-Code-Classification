# problem title : Best Time to Buy and Sell Stock with Cooldown
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sold, held, reset = 0, -float('inf'), 0
        for p in prices:
            pre_sold = sold
            sold = held + p
            held = max(held, reset - p)
            reset = max(reset, pre_sold)
        return max(sold, reset)
