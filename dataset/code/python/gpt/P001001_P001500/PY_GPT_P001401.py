# problem title : Maximum Size Subarray Sum Equals K
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        seen = {0: -1}
        prefix = 0
        max_len = 0

        for i, x in enumerate(nums):
            prefix += x
            if prefix - k in seen:
                max_len = max(max_len, i - seen[prefix - k])
            if prefix not in seen:
                seen[prefix] = i

        return max_len
