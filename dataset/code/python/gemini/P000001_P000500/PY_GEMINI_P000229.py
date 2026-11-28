from typing import List

class Solution:
    def rowWithMax1s(self, arr: List[List[int]], n: int, m: int) -> int:
        r, c = 0, m - 1
        max_row = -1

        while r < n and c >= 0:
            if arr[r][c] == 1:
                max_row = r
                c -= 1
            else:
                r += 1

        return max_row