
from typing import List

class Solution:
    def maxSumIncreasingSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        dp = arr[:]
        for i in range(1, n):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i] = max(dp[i], dp[j] + arr[i])
        return max(dp)
