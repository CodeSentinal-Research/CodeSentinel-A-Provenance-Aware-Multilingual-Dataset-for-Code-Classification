
from typing import List, Tuple

class Solution:
    def findAllPairs(self, nums: List[int], target: int) -> List[Tuple[int, int]]:
        from collections import Counter
        cnt = Counter(nums)
        res = []
        seen = set()
        for x in nums:
            y = target - x
            if y in cnt:
                key = (min(x, y), max(x, y))
                if key not in seen:
                    if x != y or cnt[x] >= 2:
                        res.append(key)
                        seen.add(key)
        return res
