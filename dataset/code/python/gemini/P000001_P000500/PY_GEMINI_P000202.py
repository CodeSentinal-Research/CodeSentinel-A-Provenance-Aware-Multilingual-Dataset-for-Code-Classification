from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        longest = 0

        for x in num_set:
            if x - 1 not in num_set:
                cur = x
                streak = 1
                while cur + 1 in num_set:
                    cur += 1
                    streak += 1
                longest = max(longest, streak)

        return longest