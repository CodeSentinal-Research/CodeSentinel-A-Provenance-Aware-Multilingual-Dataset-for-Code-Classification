from typing import List

class Solution:
    def NumberofElementsInIntersection(self, a: List[int], b: List[int], n: int, m: int) -> int:
        return len(set(a) & set(b))