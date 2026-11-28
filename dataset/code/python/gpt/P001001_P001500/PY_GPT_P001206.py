# problem title : Predict the Winner
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = list(nums)

        for diff in range(1, n):
            for i in range(n - diff):
                j = i + diff
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i])

        return dp[0] >= 0
