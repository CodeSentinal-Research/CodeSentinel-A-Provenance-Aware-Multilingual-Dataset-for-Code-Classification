from collections import defaultdict
from typing import List

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        first = {}
        last = {}
        count = defaultdict(int)

        for i, x in enumerate(nums):
            if x not in first:
                first[x] = i
            last[x] = i
            count[x] += 1

        degree = max(count.values())
        min_len = len(nums)

        for x, cnt in count.items():
            if cnt == degree:
                min_len = min(min_len, last[x] - first[x] + 1)

        return min_len