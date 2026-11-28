from typing import List

class Solution:
    def find3Numbers(self, nums: List[int], target: int) -> bool:
        nums.sort()
        n = len(nums)
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if cur_sum == target:
                    return True
                elif cur_sum < target:
                    l += 1
                else:
                    r -= 1
        return False