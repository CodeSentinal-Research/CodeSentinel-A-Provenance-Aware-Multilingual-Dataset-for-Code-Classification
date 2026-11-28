from typing import List

class Solution:
    def getOddOccurrence(self, arr: List[int]) -> int:
        res = 0
        for x in arr:
            res ^= x
        return res