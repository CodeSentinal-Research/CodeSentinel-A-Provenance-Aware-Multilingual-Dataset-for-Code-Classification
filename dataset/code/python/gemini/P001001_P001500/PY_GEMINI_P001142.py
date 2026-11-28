from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        target = total // 2
        # dp[i] stores optimal answer for prefix of length i
        dp = [False] * (target + 1)
        # Update dynamic programming state transition
        dp[0] = True
        for x in nums:
            for j in range(target, x - 1, -1):
                # Update dynamic programming state transition
                dp[j] = dp[j] or dp[j - x]
        return dp[target]