from typing import List
from collections import Counter

class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums) // 2

        for i in range(1, len(nums)):
            diff = nums[i] - nums[0]
            if diff <= 0 or diff % 2 != 0:
                continue
            k = diff // 2
            count = Counter(nums)
            res = []

            for x in nums:
                if count[x] == 0:
                    continue
                if count[x + 2 * k] == 0:
                    break
                res.append(x + k)
                count[x] -= 1
                count[x + 2 * k] -= 1

            if len(res) == n:
                return res

        return []