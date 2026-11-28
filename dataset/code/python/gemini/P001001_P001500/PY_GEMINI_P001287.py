from typing import List

class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        def can_divide(target: int) -> bool:
            pieces = 0
            cur_sum = 0
            for s in sweetness:
                cur_sum += s
                if cur_sum >= target:
                    pieces += 1
                    cur_sum = 0
            return pieces >= k + 1

        l, r = min(sweetness), sum(sweetness) // (k + 1)
        ans = l

        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if can_divide(mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1

        return ans