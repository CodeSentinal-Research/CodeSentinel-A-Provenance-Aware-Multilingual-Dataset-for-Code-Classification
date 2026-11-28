# problem title : Minimize the Maximum Pair Difference
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        if p == 0:
            return 0
        nums.sort()
        def can_form(diff: int) -> bool:
            count = 0
            i = 0
            while i < len(nums) - 1:
                if nums[i + 1] - nums[i] <= diff:
                    count += 1
                    i += 2
                else:
                    i += 1
            return count >= p

        left, right = 0, nums[-1] - nums[0]
        ans = right
        while left <= right:
            mid = left + (right - left) // 2
            if can_form(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
