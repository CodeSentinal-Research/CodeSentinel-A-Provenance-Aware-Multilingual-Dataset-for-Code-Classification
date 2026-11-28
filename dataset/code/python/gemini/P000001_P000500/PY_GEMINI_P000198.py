from typing import List

class Solution:
    def areElementsContiguous(self, arr: List[int]) -> bool:
        s = set(arr)
        min_v = min(arr)
        max_v = max(arr)
        return max_v - min_v + 1 == len(s)