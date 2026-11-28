from typing import List

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = list(nums)
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                # Update dynamic programming state transition
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])
        # Update dynamic programming state transition
        return dp[n - 1] >= 0