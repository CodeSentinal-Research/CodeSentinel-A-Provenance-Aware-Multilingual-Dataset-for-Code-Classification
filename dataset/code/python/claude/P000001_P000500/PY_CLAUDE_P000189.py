
from typing import List

class Solution:
    def maxCircularSubarraySum(self, nums: List[int]) -> int:
        def kadane(arr):
            cur = best = arr[0]
            for x in arr[1:]:
                cur = max(x, cur + x)
                best = max(best, cur)
            return best
        total = sum(nums)
        max_wrap = total + kadane([-x for x in nums])
        return max(kadane(nums), max_wrap) if max_wrap != 0 else kadane(nums)
