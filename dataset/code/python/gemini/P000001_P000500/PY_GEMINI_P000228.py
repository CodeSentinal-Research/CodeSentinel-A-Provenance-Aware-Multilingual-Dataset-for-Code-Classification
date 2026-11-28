from typing import List

class Solution:
    def search(self, matrix: List[List[int]], n: int, m: int, x: int) -> bool:
        """Performs search to locate target element within the given collection."""
        r, c = 0, m - 1
        while r < n and c >= 0:
            if matrix[r][c] == x:
                return True
            elif matrix[r][c] > x:
                c -= 1
            else:
                r += 1
        return False