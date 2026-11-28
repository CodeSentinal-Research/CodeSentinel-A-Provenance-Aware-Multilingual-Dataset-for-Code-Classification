from typing import List

class Solution:
    def segregateElements(self, arr: List[int]) -> None:
        pos = [x for x in arr if x >= 0]
        neg = [x for x in arr if x < 0]
        arr[:] = pos + neg