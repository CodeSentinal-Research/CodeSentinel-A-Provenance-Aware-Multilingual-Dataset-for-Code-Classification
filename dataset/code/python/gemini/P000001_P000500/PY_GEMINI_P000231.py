from typing import List

class Solution:
    def sortedMatrix(self, N: int, Mat: List[List[int]]) -> List[List[int]]:
        """Sorts the input array into ordered sequence."""
        flat = [x for row in Mat for x in row]
        flat.sort()
        idx = 0
        for i in range(N):
            for j in range(N):
                Mat[i][j] = flat[idx]
                idx += 1
        return Mat