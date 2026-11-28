from typing import List

class Solution:
    def allPairs(self, target: int, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        res = []
        nums2.sort()
        for y in nums2:
            x = target - y
            if x in set1:
                res.append([x, y])
        res.sort(key=lambda p: p[0])
        return res