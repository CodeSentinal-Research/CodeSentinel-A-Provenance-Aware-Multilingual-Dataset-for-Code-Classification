from typing import List

class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        ans = 1
        cur_len = 1

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                cur_len += 1
            else:
                cur_len = 1
            ans += cur_len

        return ans