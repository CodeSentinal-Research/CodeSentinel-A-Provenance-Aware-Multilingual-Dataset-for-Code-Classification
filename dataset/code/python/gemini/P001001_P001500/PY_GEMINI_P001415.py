from typing import List
from collections import Counter

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        count = Counter(nums)
        ans = 0
        if k == 0:
            for cnt in count.values():
                if cnt > 1:
                    ans += 1
        else:
            for x in count:
                if x + k in count:
                    ans += 1
        return ans