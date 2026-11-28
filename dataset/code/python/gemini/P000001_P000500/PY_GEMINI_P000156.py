from typing import List

class Solution:
    def maxConsecutiveZeros(self, nums: List[int]) -> int:
        max_zeros = cur_zeros = 0
        for x in nums:
            if x == 0:
                cur_zeros += 1
                max_zeros = max(max_zeros, cur_zeros)
            else:
                cur_zeros = 0
        return max_zeros