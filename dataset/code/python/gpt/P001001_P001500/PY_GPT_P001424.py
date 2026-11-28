# problem title : Unique Number of Occurrences
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = Counter(arr)
        return len(count.values()) == len(set(count.values()))
