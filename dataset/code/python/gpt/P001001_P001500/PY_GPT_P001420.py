# problem title : Longest Arithmetic Subsequence With Given Difference
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = defaultdict(int)
        for x in arr:
            dp[x] = dp[x - difference] + 1
        return max(dp.values())
