# problem title : Count Good Pairs
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count = Counter(nums)
        return sum(v * (v - 1) // 2 for v in count.values())
