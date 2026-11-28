from typing import List

class Solution:
    def minProductSubarray(self, nums: List[int]) -> int:
        min_prod = max_prod = ans = nums[0]
        for x in nums[1:]:
            candidates = (x, min_prod * x, max_prod * x)
            min_prod = min(candidates)
            max_prod = max(candidates)
            ans = min(ans, min_prod)
        return ans