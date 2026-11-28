from collections import defaultdict
from typing import List

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        freq = defaultdict(int)
        count = 0
        for x in nums:
            count += freq[target - x]
            freq[x] += 1
        return count