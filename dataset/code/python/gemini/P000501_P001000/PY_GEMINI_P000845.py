from typing import List

class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def can_rob(cap: int) -> bool:
            count = 0
            i = 0
            while i < len(nums):
                if nums[i] <= cap:
                    count += 1
                    i += 2
                else:
                    i += 1
            return count >= k

        left, right = min(nums), max(nums)
        ans = right
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if can_rob(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans