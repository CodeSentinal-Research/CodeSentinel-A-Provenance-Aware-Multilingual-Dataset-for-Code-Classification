# problem title : 3Sum Closest
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        closest_sum = nums[0] + nums[1] + nums[2]

        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if abs(cur_sum - target) < abs(closest_sum - target):
                    closest_sum = cur_sum
                if cur_sum < target:
                    l += 1
                elif cur_sum > target:
                    r -= 1
                else:
                    return target

        return closest_sum
