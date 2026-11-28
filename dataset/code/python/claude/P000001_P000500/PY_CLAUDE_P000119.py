
from typing import List

class Solution:
    def separateEvenOdd(self, nums: List[int]) -> List[int]:
        evens = [x for x in nums if x % 2 == 0]
        odds  = [x for x in nums if x % 2 != 0]
        return evens + odds
