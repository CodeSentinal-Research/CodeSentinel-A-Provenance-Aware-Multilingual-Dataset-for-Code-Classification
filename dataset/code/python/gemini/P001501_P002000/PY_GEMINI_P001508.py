from typing import List
from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = defaultdict(int)
        l = 0
        for r, f in enumerate(fruits):
            count[f] += 1
            if len(count) > 2:
                count[fruits[l]] -= 1
                if count[fruits[l]] == 0:
                    del count[fruits[l]]
                l += 1
        return len(fruits) - l