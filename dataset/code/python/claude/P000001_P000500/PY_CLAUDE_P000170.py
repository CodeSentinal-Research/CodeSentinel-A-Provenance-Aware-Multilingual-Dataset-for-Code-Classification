
from typing import List, Optional
from collections import Counter

class Solution:
    def firstNonRepeating(self, nums: List[int]) -> Optional[int]:
        cnt = Counter(nums)
        for x in nums:
            if cnt[x] == 1: return x
        return None
