
from typing import List

class Solution:
    def findMaxConsecutiveZeros(self, nums: List[int]) -> int:
        best = cur = 0
        for x in nums:
            cur = cur + 1 if x == 0 else 0
            best = max(best, cur)
        return best
