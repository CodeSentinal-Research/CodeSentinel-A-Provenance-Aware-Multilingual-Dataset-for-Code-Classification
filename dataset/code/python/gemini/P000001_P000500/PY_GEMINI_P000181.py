from typing import List

class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        def helper(L, M):
            max_l = ans = 0
            sum_l = sum(nums[:L])
            sum_m = sum(nums[L:L + M])
            max_l = sum_l
            ans = sum_l + sum_m

            for i in range(L + M, len(nums)):
                sum_l += nums[i - M] - nums[i - L - M]
                max_l = max(max_l, sum_l)
                sum_m += nums[i] - nums[i - M]
                ans = max(ans, max_l + sum_m)
            return ans

        return max(helper(firstLen, secondLen), helper(secondLen, firstLen))