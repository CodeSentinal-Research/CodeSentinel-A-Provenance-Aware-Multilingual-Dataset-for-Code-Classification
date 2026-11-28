from typing import List

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def can_split(max_sum: int) -> bool:
            pieces = 1
            curr_sum = 0
            for x in nums:
                if curr_sum + x > max_sum:
                    pieces += 1
                    curr_sum = x
                else:
                    curr_sum += x
            return pieces <= k

        left, right = max(nums), sum(nums)
        ans = right
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if can_split(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans