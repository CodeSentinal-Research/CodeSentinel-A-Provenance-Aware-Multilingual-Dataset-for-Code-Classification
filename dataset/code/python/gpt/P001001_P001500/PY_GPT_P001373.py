# problem title : Contains Duplicate II
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}
        for i, n in enumerate(nums):
            if n in seen and i - seen[n] <= k:
                return True
            seen[n] = i
        return False
