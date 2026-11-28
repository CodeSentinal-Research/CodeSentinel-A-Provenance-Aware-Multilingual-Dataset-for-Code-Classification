from typing import List

class Solution:
    def getMedian(self, arr1: List[int], arr2: List[int]) -> float:
        merged = sorted(arr1 + arr2)
        n = len(merged)
        return (merged[n // 2 - 1] + merged[n // 2]) / 2.0