
from typing import List
from collections import Counter

class Solution:
    def mostFrequent(self, nums: List[int]) -> int:
        return Counter(nums).most_common(1)[0][0]
