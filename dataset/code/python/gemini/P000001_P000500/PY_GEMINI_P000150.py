from typing import List

class Solution:
    def sortMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        """Sorts the input array into ordered sequence."""
        elements = [x for row in matrix for x in row]
        elements.sort()
        idx = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = elements[idx]
                idx += 1
        return matrix