from collections import Counter
from typing import List

class Solution:
    def mostFrequent(self, nums: List[int]) -> int:
        freq = Counter(nums)
        return max(freq.keys(), key=lambda k: freq[k])