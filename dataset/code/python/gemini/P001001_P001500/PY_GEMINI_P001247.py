from typing import List
from collections import deque

class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        sorted_nums2 = sorted((val, idx) for idx, val in enumerate(nums2))

        res = [0] * len(nums1)
        remaining = []
        j = 0

        for val, idx in sorted_nums2:
            while j < len(nums1) and nums1[j] <= val:
                remaining.append(nums1[j])
                j += 1
            if j < len(nums1):
                res[idx] = nums1[j]
                j += 1
            else:
                res[idx] = remaining.pop()

        return res