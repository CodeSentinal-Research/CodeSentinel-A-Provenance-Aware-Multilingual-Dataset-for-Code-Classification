# problem title : Minimum Difference Between Highest and Lowest of K Scores
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        if k == 1:
            return 0
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
