from typing import List
from collections import Counter

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        prod_count = Counter()
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                prod_count[nums[i] * nums[j]] += 1
        return sum(8 * cnt * (cnt - 1) // 2 for cnt in prod_count.values())