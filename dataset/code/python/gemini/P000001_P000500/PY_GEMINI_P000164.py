from typing import List

class Solution:
    def countTriplets(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        count = 0
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if cur_sum == target:
                    count += 1
                    l += 1
                    r -= 1
                elif cur_sum < target:
                    l += 1
                else:
                    r -= 1
        return count