from collections import Counter
from typing import List

class Solution:
    def findCommonElements(self, mat: List[List[int]]) -> List[int]:
        if not mat:
            return []
        common = set(mat[0])
        for row in mat[1:]:
            common &= set(row)
        return sorted(list(common))