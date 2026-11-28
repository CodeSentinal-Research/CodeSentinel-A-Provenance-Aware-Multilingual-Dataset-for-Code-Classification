from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        even, odd = 0, 0
        for x in nums:
            even = max(even, odd + x)
            odd = max(odd, even - x)
        return even