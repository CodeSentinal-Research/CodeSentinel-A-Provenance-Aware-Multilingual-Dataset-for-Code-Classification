from typing import List

class Solution:
    def countZeroes(self, A: List[List[int]], N: int) -> int:
        r, c = 0, N - 1
        count = 0

        while r < N and c >= 0:
            if A[r][c] == 0:
                count += (c + 1)
                r += 1
            else:
                c -= 1

        return count