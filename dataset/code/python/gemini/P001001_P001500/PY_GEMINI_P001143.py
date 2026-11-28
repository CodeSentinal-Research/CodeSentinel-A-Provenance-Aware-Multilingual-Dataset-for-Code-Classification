from typing import List

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        if (total + target) % 2 != 0 or total < abs(target):
            return 0
        s1 = (total + target) // 2
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (s1 + 1)
        # Update dynamic programming state transition
        dp[0] = 1
        for x in nums:
            for j in range(s1, x - 1, -1):
                # Update dynamic programming state transition
                dp[j] += dp[j - x]
        return dp[s1]