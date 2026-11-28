from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        c1 = c2 = None
        cnt1 = cnt2 = 0

        for x in nums:
            if x == c1:
                cnt1 += 1
            elif x == c2:
                cnt2 += 1
            elif cnt1 == 0:
                c1, cnt1 = x, 1
            elif cnt2 == 0:
                c2, cnt2 = x, 1
            else:
                cnt1 -= 1
                cnt2 -= 1

        res = []
        n = len(nums)
        if nums.count(c1) > n // 3:
            res.append(c1)
        if c2 is not None and c2 != c1 and nums.count(c2) > n // 3:
            res.append(c2)

        return res