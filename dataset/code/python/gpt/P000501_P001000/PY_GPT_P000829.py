# problem title : Capacity To Ship Packages Within D Days
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def can_ship(cap: int) -> bool:
            d = 1
            curr = 0
            for w in weights:
                if curr + w > cap:
                    d += 1
                    curr = w
                else:
                    curr += w
            return d <= days

        left, right = max(weights), sum(weights)
        ans = right
        while left <= right:
            mid = left + (right - left) // 2
            if can_ship(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
