# problem title : Maximum Candies Allocated to K Children
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:
            return 0
        left, right = 1, max(candies)
        ans = 0
        while left <= right:
            mid = left + (right - left) // 2
            children = sum(c // mid for c in candies)
            if children >= k:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
