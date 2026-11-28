# problem title : Subarray Sum Equals K
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        count[0] = 1
        prefix = 0
        ans = 0

        for x in nums:
            prefix += x
            ans += count[prefix - k]
            count[prefix] += 1

        return ans
