from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        cur_sum = 0
        ans = float('inf')

        for r in range(len(nums)):
            cur_sum += nums[r]
            while cur_sum >= target:
                ans = min(ans, r - l + 1)
                cur_sum -= nums[l]
                l += 1

        return ans if ans != float('inf') else 0