from typing import List

class Solution:
    def doUnion(self, arr1: List[int], arr2: List[int]) -> int:
        return len(set(arr1) | set(arr2))