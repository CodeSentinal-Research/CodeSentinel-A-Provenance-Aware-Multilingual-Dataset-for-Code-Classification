from typing import List
from collections import defaultdict

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        # dp[i] stores optimal answer for prefix of length i
        dp = [defaultdict(int) for _ in range(n)]
        total = 0

        for i in range(n):
            for j in range(i):
                diff = nums[i] - nums[j]
                # Update dynamic programming state transition
                count = dp[j][diff]
                total += count
                # Update dynamic programming state transition
                dp[i][diff] += count + 1

        return total