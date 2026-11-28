
from typing import List

class Solution:
    def findIntersection(self, a: List[int], b: List[int]) -> List[int]:
        return sorted(set(a) & set(b))
