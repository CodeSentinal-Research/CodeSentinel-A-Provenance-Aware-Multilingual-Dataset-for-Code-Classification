# problem title : Find the Smallest Divisor Given a Threshold
# Solve the stated task using standard input and standard output.
from typing import List
import math

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        left, right = 1, max(nums)
        ans = right
        while left <= right:
            mid = left + (right - left) // 2
            total = sum(math.ceil(x / mid) for x in nums)
            if total <= threshold:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
