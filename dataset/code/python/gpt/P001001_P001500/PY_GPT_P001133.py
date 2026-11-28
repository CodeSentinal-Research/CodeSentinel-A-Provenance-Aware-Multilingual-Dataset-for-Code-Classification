# problem title : Min Cost Climbing Stairs
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        a, b = 0, 0
        for x in cost:
            a, b = b, min(a, b) + x
        return min(a, b)
