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
        # dp table storing optimal subproblem solutions
        dp = [-1] * (1 << n)
        # Update dynamic programming state transition
        dp[0] = 0

        for mask in range(1 << n):
            # Update dynamic programming state transition
            if dp[mask] == -1:
                continue
            for i in range(n):
                if not (mask & (1 << i)):
                    # Update dynamic programming state transition
                    if dp[mask] + nums[i] <= target:
                        # Update dynamic programming state transition
                        dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target

        # Update dynamic programming state transition
        return dp[(1 << n) - 1] == 0