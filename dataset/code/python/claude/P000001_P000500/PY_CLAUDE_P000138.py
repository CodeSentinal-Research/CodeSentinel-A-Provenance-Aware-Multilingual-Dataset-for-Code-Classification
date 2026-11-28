
from typing import List

class Solution:
    def mergeSorted(self, a: List[int], b: List[int]) -> List[int]:
        res = []
        i = j = 0
        while i < len(a) and j < len(b):
            if a[i] <= b[j]: res.append(a[i]); i += 1
            else: res.append(b[j]); j += 1
        res.extend(a[i:])
        res.extend(b[j:])
        return res
