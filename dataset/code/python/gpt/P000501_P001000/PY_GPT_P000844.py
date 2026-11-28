# problem title : Maximum Tastiness of Candy Basket
# Solve the stated task using standard input and standard output.
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
        while left <= right:
            mid = left + (right - left) // 2
            if can_pick(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
