
from typing import List, Tuple

class Solution:
    def findMissingRepeating(self, nums: List[int]) -> Tuple[int, int]:
        n = len(nums)
        seen = {}
        repeating = -1
        for x in nums:
            seen[x] = seen.get(x, 0) + 1
            if seen[x] == 2:
                repeating = x
        missing = -1
        for i in range(1, n + 1):
            if seen.get(i, 0) == 0:
                missing = i
                break
        return repeating, missing
