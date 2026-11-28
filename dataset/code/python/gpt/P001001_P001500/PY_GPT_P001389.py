# problem title : Longest Subarray with Equal Number of 0s and 1s
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        seen = {0: -1}
        prefix = 0
        max_len = 0
        for i, x in enumerate(nums):
            prefix += 1 if x == 1 else -1
            if prefix in seen:
                max_len = max(max_len, i - seen[prefix])
            else:
                seen[prefix] = i
        return max_len
