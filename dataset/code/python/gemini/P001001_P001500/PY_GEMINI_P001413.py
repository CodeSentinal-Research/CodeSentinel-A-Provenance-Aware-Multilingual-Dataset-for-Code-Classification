from typing import List
from collections import Counter

class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        count = Counter(nums)
        uniques = [x for x, cnt in count.items() if cnt == 1]
        return max(uniques) if uniques else -1