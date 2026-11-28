from typing import List
from collections import defaultdict

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        count = defaultdict(int)
        count[0] = 1
        cur_sum = 0
        ans = 0

        for x in nums:
            cur_sum += x
            ans += count[cur_sum - goal]
            count[cur_sum] += 1

        return ans