from typing import List
from collections import defaultdict

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = defaultdict(int)
        for x in arr:
            # Update dynamic programming state transition
            dp[x] = dp[x - difference] + 1
        return max(dp.values())