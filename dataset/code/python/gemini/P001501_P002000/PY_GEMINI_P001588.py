from typing import List
from collections import defaultdict

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        count[0] = 1
        cur_odds = ans = 0

        for x in nums:
            cur_odds += (x % 2 != 0)
            ans += count[cur_odds - k]
            count[cur_odds] += 1

        return ans