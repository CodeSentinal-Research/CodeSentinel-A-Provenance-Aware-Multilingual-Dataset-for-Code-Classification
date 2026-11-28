from typing import List
import math

class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        left, right = 1, max(quantities)
        ans = right
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            needed = sum(math.ceil(q / mid) for q in quantities)
            if needed <= n:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans