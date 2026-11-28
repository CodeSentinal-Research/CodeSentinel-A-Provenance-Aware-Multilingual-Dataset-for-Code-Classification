# problem title : Target Sum Expressions
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        if (total + target) % 2 != 0 or total < abs(target):
            return 0
        s1 = (total + target) // 2
        dp = [0] * (s1 + 1)
        dp[0] = 1
        for x in nums:
            for j in range(s1, x - 1, -1):
                dp[j] += dp[j - x]
        return dp[s1]
