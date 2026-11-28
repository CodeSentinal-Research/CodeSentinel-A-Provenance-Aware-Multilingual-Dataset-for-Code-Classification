
from typing import List

class Solution:
    def chocolateDistribution(self, nums: List[int], m: int) -> int:
        if m == 0 or not nums: return 0
        nums.sort()
        n = len(nums)
        if m > n: return -1
        min_diff = float('inf')
        for i in range(n - m + 1):
            min_diff = min(min_diff, nums[i + m - 1] - nums[i])
        return min_diff
