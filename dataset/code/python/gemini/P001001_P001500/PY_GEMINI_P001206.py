from typing import List

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = list(nums)

        for diff in range(1, n):
            for i in range(n - diff):
                j = i + diff
                # Update dynamic programming state transition
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i])

        # Update dynamic programming state transition
        return dp[0] >= 0