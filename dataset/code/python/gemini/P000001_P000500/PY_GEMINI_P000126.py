from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]
        n = len(nums)

        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if abs(cur_sum - target) < abs(closest - target):
                    closest = cur_sum
                if cur_sum < target:
                    l += 1
                elif cur_sum > target:
                    r -= 1
                else:
                    return target
        return closest