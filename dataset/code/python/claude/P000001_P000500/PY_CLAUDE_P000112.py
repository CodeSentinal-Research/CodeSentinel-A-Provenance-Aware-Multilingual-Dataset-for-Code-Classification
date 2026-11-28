
from typing import List

class Solution:
    def secondSmallest(self, nums: List[int]) -> int:
        first = second = float('inf')
        for x in nums:
            if x < first:
                second = first
                first = x
            elif x < second and x != first:
                second = x
        return second if second != float('inf') else -1
