# problem title : Divide Array Into Equal Pairs
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        return all(cnt % 2 == 0 for cnt in Counter(nums).values())
