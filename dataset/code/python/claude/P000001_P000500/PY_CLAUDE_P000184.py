
from typing import List

class Solution:
    def longestSubarrayWithSumK(self, nums: List[int], k: int) -> int:
        prefix_map = {0: -1}
        prefix = 0
        best = 0
        for i, x in enumerate(nums):
            prefix += x
            if prefix - k in prefix_map:
                best = max(best, i - prefix_map[prefix - k])
            if prefix not in prefix_map:
                prefix_map[prefix] = i
        return best
