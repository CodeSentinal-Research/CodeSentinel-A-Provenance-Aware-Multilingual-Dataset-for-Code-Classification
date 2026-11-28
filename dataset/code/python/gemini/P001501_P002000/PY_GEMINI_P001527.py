from typing import List

class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        ans = float('inf')
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        for size in range(l, r + 1):
            for i in range(n - size + 1):
                cur_sum = prefix[i + size] - prefix[i]
                if cur_sum > 0:
                    ans = min(ans, cur_sum)

        return ans if ans != float('inf') else -1