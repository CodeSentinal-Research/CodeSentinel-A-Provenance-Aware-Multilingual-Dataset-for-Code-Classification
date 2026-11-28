from typing import List

class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        def can_pick(target: int) -> bool:
            count = 1
            last = price[0]
            for i in range(1, len(price)):
                if price[i] - last >= target:
                    count += 1
                    last = price[i]
                    if count == k:
                        return True
            return False

        left, right = 0, price[-1] - price[0]
        ans = 0
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if can_pick(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans