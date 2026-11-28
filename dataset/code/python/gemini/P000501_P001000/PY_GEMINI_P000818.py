from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        """Performs search to locate target element within the given collection."""
        left, right = 0, len(nums) - 1
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            elif nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False