from typing import List

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        """Sorts the input array into ordered sequence."""
        sorted_nums = sorted(nums)
        l, r = 0, len(nums) - 1

        while l < len(nums) and nums[l] == sorted_nums[l]:
            l += 1
        while r > l and nums[r] == sorted_nums[r]:
            r -= 1

        return r - l + 1 if r > l else 0