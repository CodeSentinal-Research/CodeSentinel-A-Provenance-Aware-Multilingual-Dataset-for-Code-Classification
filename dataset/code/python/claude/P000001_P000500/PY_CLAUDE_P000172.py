
from typing import List

class Solution:
    def segregateEvenOdd(self, nums: List[int]) -> List[int]:
        return [x for x in nums if x%2==0] + [x for x in nums if x%2!=0]
