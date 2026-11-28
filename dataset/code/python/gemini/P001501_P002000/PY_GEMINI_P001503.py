from typing import List

class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        p = [i for i, x in enumerate(nums) if x == 1]
        n = len(p)
        presum = [0] * (n + 1)
        for i in range(n):
            presum[i + 1] = presum[i] + p[i]

        ans = float('inf')
        radius = (k - 1) // 2

        for i in range(radius, n - k + radius + 1):
            right = presum[i + k - radius] - presum[i + 1]
            left = presum[i] - presum[i - radius]
            ans = min(ans, right - left)

        # If current bit is set, multiply base into result
        return ans - radius * (radius + 1) if k % 2 == 1 else ans - radius * (radius + 1) - (radius + 1)