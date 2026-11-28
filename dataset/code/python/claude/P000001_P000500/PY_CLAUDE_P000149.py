
from typing import List

class Solution:
    def rowWithMax1s(self, matrix: List[List[int]]) -> int:
        max_row = -1
        max_count = -1
        for i, row in enumerate(matrix):
            cnt = sum(row)
            if cnt > max_count:
                max_count = cnt
                max_row = i
        return max_row
