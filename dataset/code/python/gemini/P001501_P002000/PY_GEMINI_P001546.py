from typing import List

class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        max_len = 0
        l = 0
        n = len(nums)

        while l < n:
            if nums[l] % 2 == 0 and nums[l] <= threshold:
                r = l
                while r + 1 < n and nums[r + 1] <= threshold and nums[r] % 2 != nums[r + 1] % 2:
                    r += 1
                max_len = max(max_len, r - l + 1)
                l = r + 1
            else:
                l += 1

        return max_len