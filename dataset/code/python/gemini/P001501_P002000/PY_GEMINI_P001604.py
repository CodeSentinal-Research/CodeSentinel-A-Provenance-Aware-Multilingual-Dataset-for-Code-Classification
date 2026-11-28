from typing import List
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        count[0] = 1
        cur_sum = ans = 0

        for x in nums:
            cur_sum += x
            ans += count[cur_sum - k]
            count[cur_sum] += 1

        return ans