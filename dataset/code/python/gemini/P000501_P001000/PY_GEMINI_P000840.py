from typing import List

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left, right = 1, max(nums)
        ans = right
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            ops = sum((x - 1) // mid for x in nums)
            if ops <= maxOperations:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans