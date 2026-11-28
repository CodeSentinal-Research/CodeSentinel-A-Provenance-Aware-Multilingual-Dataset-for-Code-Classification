# problem title : Delete and Earn
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        count = Counter(nums)
        max_val = max(nums)
        values = [count[i] * i for i in range(max_val + 1)]

        rob1, rob2 = 0, 0
        for v in values:
            rob1, rob2 = rob2, max(rob1 + v, rob2)

        return rob2
