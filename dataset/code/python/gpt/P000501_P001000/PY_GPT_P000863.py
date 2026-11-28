# problem title : Single Number III
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor_all = 0
        for x in nums:
            xor_all ^= x
        
        diff = xor_all & (-xor_all)
        a, b = 0, 0
        for x in nums:
            if x & diff:
                a ^= x
            else:
                b ^= x
        return [a, b]
