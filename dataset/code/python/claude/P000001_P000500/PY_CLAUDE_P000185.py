
from typing import List

class Solution:
    def longestSubarrayEqual01(self, nums: List[int]) -> int:

        mp = {0: -1}
        prefix = 0
        best = 0
        for i, x in enumerate(nums):
            prefix += 1 if x == 1 else -1
            if prefix in mp:
                best = max(best, i - mp[prefix])
            else:
                mp[prefix] = i
        return best
