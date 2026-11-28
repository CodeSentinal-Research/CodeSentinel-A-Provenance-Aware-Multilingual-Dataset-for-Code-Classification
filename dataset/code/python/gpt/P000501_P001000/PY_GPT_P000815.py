# problem title : Find First and Last Position of Element in Sorted Array
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def find_bound(is_first: bool) -> int:
            left, right = 0, len(nums) - 1
            ans = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    ans = mid
                    if is_first:
                        right = mid - 1
                    else:
                        left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return ans

        return [find_bound(True), find_bound(False)]
