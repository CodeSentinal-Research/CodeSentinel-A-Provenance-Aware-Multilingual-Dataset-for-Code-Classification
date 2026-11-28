from typing import List

class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        used_bits = 0
        l = 0
        max_len = 0

        for r in range(len(nums)):
            while (used_bits & nums[r]) != 0:
                used_bits ^= nums[l]
                l += 1
            used_bits |= nums[r]
            max_len = max(max_len, r - l + 1)

        return max_len