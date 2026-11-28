# problem title : Minimum Number of Days to Make m Bouquets
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1
        
        def can_make(day: int) -> bool:
            bouquets = 0
            flowers = 0
            for b in bloomDay:
                if b <= day:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                else:
                    flowers = 0
            return bouquets >= m

        left, right = min(bloomDay), max(bloomDay)
        ans = -1
        while left <= right:
            mid = left + (right - left) // 2
            if can_make(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
