from typing import List

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0:
            return -1
        if target == 0:
            return len(nums)

        cur_sum = 0
        max_len = -1
        l = 0

        for r, num in enumerate(nums):
            cur_sum += num
            while cur_sum > target and l <= r:
                cur_sum -= nums[l]
                l += 1
            if cur_sum == target:
                max_len = max(max_len, r - l + 1)

        return len(nums) - max_len if max_len != -1 else -1