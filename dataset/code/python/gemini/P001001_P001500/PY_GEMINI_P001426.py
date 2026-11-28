from typing import List
from collections import Counter

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        count = Counter(arr)
        luckies = [k for k, v in count.items() if k == v]
        return max(luckies) if luckies else -1