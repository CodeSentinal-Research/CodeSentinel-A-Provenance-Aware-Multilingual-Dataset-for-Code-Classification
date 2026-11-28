# problem title : Relative Sort Array
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        rank = {val: i for i, val in enumerate(arr2)}
        return sorted(arr1, key=lambda x: (rank.get(x, 1000 + x), x))
