from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        ans = right
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            hours = sum(math.ceil(p / mid) for p in piles)
            if hours <= h:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans