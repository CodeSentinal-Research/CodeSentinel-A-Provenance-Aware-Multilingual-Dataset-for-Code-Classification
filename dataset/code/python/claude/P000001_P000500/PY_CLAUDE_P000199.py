
from typing import List

class Solution:
    def findOddOccurrence(self, nums: List[int]) -> int:
        res = 0
        for x in nums: res ^= x
        return res
