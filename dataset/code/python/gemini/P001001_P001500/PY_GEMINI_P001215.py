from typing import List

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        memo = {}

        def dp(l: int, r: int, k: int) -> int:
            if l > r:
                return 0
            while r > l and boxes[r] == boxes[r - 1]:
                r -= 1
                k += 1
            if (l, r, k) in memo:
                return memo[(l, r, k)]

            res = dp(l, r - 1, 0) + (k + 1) * (k + 1)
            for i in range(l, r):
                if boxes[i] == boxes[r]:
                    res = max(res, dp(i + 1, r - 1, 0) + dp(l, i, k + 1))

            memo[(l, r, k)] = res
            return res

        return dp(0, n - 1, 0)