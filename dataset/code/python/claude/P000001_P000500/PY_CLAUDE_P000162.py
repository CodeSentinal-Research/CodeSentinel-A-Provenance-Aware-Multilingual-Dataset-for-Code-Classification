
from typing import List

class Solution:
    def countPairsWithSum(self, nums: List[int], target: int) -> int:
        from collections import Counter
        cnt = Counter(nums)
        count = 0
        for x in cnt:
            y = target - x
            if y in cnt:
                if x == y:
                    count += cnt[x] * (cnt[x] - 1) // 2
                elif x < y:
                    count += cnt[x] * cnt[y]
        return count
