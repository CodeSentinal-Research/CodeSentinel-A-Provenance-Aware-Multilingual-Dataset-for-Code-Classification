# problem title : Number of Equivalent Domino Pairs
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count = Counter(tuple(sorted(d)) for d in dominoes)
        return sum(v * (v - 1) // 2 for v in count.values())
