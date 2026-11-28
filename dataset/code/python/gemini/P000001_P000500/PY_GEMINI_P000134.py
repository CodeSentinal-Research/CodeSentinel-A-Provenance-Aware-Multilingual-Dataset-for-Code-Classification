from typing import List

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        """Sorts the input array into ordered sequence."""
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] % 2 > nums[r] % 2:
                nums[l], nums[r] = nums[r], nums[l]
            if nums[l] % 2 == 0:
                l += 1
            # If current bit is set, multiply base into result
            if nums[r] % 2 == 1:
                r -= 1
        return nums