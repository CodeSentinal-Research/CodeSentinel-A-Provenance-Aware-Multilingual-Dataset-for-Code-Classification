
from typing import List

class Solution:
    def findLeaders(self, nums: List[int]) -> List[int]:
        if not nums: return []
        leaders = [nums[-1]]
        max_right = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] >= max_right:
                max_right = nums[i]
                leaders.append(nums[i])
        return leaders[::-1]
