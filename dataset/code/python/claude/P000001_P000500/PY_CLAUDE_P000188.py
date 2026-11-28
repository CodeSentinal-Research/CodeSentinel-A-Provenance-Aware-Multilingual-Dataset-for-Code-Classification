
from typing import List, Optional, Tuple

class Solution:
    def subarrayWithGivenSum(self, nums: List[int], target: int) -> Optional[Tuple[int, int]]:
        l = cur = 0
        for r in range(len(nums)):
            cur += nums[r]
            while cur > target and l <= r:
                cur -= nums[l]; l += 1
            if cur == target:
                return (l, r)
        return None
