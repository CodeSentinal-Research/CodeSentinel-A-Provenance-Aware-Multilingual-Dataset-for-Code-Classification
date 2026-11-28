from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """Performs search to locate target element within the given collection."""
        left, right = 0, len(nums) - 1
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1