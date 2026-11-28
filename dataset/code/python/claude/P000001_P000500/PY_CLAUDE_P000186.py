
from typing import List

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        pos = neg = 0
        best = 0
        for x in nums:
            if x == 0:
                pos = neg = 0
            elif x > 0:
                pos += 1
                neg = neg + 1 if neg > 0 else 0
            else:
                pos, neg = neg + 1 if neg > 0 else 0, pos + 1
            best = max(best, pos)
        return best
