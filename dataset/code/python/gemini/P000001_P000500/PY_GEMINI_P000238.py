from typing import List

class Solution:
    def isOrthogonal(self, matrix: List[List[int]], n: int) -> bool:
        """Sorts the input array into ordered sequence."""
        # A * A^T == Identity Matrix
        for i in range(n):
            for j in range(n):
                dot = sum(matrix[i][k] * matrix[j][k] for k in range(n))
                if i == j and dot != 1:
                    return False
                if i != j and dot != 0:
                    return False
        return True