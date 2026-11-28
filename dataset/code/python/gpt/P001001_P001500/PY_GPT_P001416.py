# problem title : Longest Harmonious Subsequence
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = Counter(nums)
        ans = 0
        for x in count:
            if x + 1 in count:
                ans = max(ans, count[x] + count[x + 1])
        return ans
