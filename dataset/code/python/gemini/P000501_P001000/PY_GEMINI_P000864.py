from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        for i, x in enumerate(nums):
            ans ^= (i ^ x)
        return ans