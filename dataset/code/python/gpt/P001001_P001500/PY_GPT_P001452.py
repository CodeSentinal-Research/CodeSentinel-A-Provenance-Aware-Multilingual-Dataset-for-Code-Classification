# problem title : Count Distinct Elements After Updates
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def countDistinct(self, nums: List[int]) -> int:
        seen = set()
        for x in nums:
            seen.add(x)
            seen.add(int(str(x)[::-1]))
        return len(seen)
