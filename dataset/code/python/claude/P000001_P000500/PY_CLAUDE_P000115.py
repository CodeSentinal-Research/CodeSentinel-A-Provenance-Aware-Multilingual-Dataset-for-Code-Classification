
from typing import List

class Solution:
    def rotateRight(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n == 0: return nums
        k %= n
        return nums[-k:] + nums[:-k] if k else nums[:]
