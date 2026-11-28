# problem title : K-Partition Problem
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k != 0:
            return False
        target = total // k
        nums.sort(reverse=True)
        if nums[0] > target:
            return False

        n = len(nums)
        dp = [-1] * (1 << n)
        dp[0] = 0

        for mask in range(1 << n):
            if dp[mask] == -1:
                continue
            for i in range(n):
                if not (mask & (1 << i)):
                    if dp[mask] + nums[i] <= target:
                        dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target

        return dp[(1 << n) - 1] == 0
