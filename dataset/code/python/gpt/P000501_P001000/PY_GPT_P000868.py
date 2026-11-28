# problem title : Total Hamming Distance
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        total = 0
        n = len(nums)
        for i in range(32):
            ones = sum((x >> i) & 1 for x in nums)
            total += ones * (n - ones)
        return total
