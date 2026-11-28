
from typing import List

class Solution:
    def majorityElementNBy3(self, nums: List[int]) -> List[int]:
        c1 = c2 = None
        cnt1 = cnt2 = 0
        for x in nums:
            if x == c1: cnt1 += 1
            elif x == c2: cnt2 += 1
            elif cnt1 == 0: c1, cnt1 = x, 1
            elif cnt2 == 0: c2, cnt2 = x, 1
            else: cnt1 -= 1; cnt2 -= 1
        res = []
        threshold = len(nums) // 3
        for c in [c1, c2]:
            if c is not None and nums.count(c) > threshold:
                res.append(c)
        return res
