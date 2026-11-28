
from typing import List

class Solution:
    def missingNumber(self, nums: List[int], n: int) -> int:
        expected = n * (n + 1) // 2
        return expected - sum(nums)
