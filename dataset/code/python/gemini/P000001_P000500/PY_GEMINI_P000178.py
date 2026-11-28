from collections import Counter
from typing import List

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        """Sorts the input array into ordered sequence."""
        freq = Counter(nums)
        return sorted(nums, key=lambda x: (-freq[x], x))