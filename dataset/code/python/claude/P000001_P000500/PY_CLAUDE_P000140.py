
from typing import List

class Solution:
    def unionArrays(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return sorted(set(nums1) | set(nums2))
