
from typing import List

class Solution:
    def moveNegatives(self, nums: List[int]) -> List[int]:
        neg = [x for x in nums if x < 0]
        pos = [x for x in nums if x >= 0]
        return neg + pos
