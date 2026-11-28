# problem title : Count Number of Pairs With Absolute Difference K
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        count = Counter(nums)
        return sum(count[x] * count[x + k] for x in count)
