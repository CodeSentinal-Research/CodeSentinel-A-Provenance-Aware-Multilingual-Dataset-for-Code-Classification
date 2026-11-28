from typing import List
from collections import deque

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_dq = deque()
        min_dq = deque()
        l = 0

        for num in nums:
            while max_dq and num > max_dq[-1]:
                max_dq.pop()
            while min_dq and num < min_dq[-1]:
                min_dq.pop()
            max_dq.append(num)
            min_dq.append(num)

            if max_dq[0] - min_dq[0] > limit:
                if max_dq[0] == nums[l]:
                    max_dq.popleft()
                if min_dq[0] == nums[l]:
                    min_dq.popleft()
                l += 1

        return len(nums) - l