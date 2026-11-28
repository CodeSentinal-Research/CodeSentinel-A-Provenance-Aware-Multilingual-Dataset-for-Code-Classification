# problem title : Single Number
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            ans ^= x
        return ans
