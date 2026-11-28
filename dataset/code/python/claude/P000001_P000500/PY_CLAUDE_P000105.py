
from typing import List, Tuple

class Solution:
    def countEvenOdd(self, nums: List[int]) -> Tuple[int, int]:
        even = sum(1 for x in nums if x % 2 == 0)
        return even, len(nums) - even
