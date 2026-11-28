from typing import List
from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        count = Counter(answers)
        ans = 0
        for x, cnt in count.items():
            group_size = x + 1
            num_groups = (cnt + group_size - 1) // group_size
            ans += num_groups * group_size
        return ans