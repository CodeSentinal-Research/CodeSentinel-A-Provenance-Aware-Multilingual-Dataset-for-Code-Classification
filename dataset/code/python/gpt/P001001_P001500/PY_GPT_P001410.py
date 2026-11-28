# problem title : Count Bad Pairs
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        total_pairs = n * (n - 1) // 2
        good_count = Counter(nums[i] - i for i in range(n))
        good_pairs = sum(cnt * (cnt - 1) // 2 for cnt in good_count.values())
        return total_pairs - good_pairs
