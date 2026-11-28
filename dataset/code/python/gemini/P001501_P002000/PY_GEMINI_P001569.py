from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        seen = set()
        l = cur_sum = max_sum = 0

        for num in nums:
            while num in seen:
                seen.remove(nums[l])
                cur_sum -= nums[l]
                l += 1
            seen.add(num)
            cur_sum += num
            max_sum = max(max_sum, cur_sum)

        return max_sum