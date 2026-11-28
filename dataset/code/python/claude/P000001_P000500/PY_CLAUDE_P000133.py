
from typing import List

class Solution:
    def rearrangeAlternately(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        res = []
        l, r = 0, n - 1
        toggle = True
        while l <= r:
            if toggle:
                res.append(nums[r])
                r -= 1
            else:
                res.append(nums[l])
                l += 1
            toggle = not toggle
        return res
