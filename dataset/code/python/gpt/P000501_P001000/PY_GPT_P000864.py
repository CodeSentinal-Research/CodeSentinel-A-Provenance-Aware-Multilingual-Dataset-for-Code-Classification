# problem title : Missing Number Using XOR
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        for i, x in enumerate(nums):
            ans ^= (i ^ x)
        return ans
