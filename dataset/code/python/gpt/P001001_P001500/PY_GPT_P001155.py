# problem title : Burst Balloons
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        A = [1] + [x for x in nums if x > 0] + [1]
        n = len(A)
        dp = [[0] * n for _ in range(n)]

        for length in range(2, n):
            for left in range(n - length):
                right = left + length
                for i in range(left + 1, right):
                    coins = dp[left][i] + dp[i][right] + A[left] * A[i] * A[right]
                    if coins > dp[left][right]:
                        dp[left][right] = coins

        return dp[0][n - 1]
