# problem title : Minimize Maximum Pair Sum
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        return max(nums[i] + nums[n - 1 - i] for i in range(n // 2))
