# problem title : Minimum Absolute Difference Pairs
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = min(arr[i] - arr[i - 1] for i in range(1, len(arr)))
        return [[arr[i - 1], arr[i]] for i in range(1, len(arr)) if arr[i] - arr[i - 1] == min_diff]
