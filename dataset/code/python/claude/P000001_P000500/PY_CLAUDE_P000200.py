
from typing import List, Tuple

class Solution:
    def findTwoOddOccurrences(self, nums: List[int]) -> Tuple[int, int]:
        xor = 0
        for x in nums: xor ^= x

        bit = xor & (-xor)
        a = b = 0
        for x in nums:
            if x & bit: a ^= x
            else: b ^= x
        return (a, b)
