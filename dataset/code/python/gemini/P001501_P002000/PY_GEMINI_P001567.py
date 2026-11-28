from typing import List
from collections import Counter

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        k = len(set(nums))
        count = Counter()
        ans = 0
        l = 0

        for r, x in enumerate(nums):
            count[x] += 1
            while len(count) == k:
                ans += len(nums) - r
                count[nums[l]] -= 1
                if count[nums[l]] == 0:
                    del count[nums[l]]
                l += 1

        return ans