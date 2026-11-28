# problem title : Number of Submatrices That Sum to Target
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        r, c = len(matrix), len(matrix[0])
        # Compute row prefix sums
        for row in matrix:
            for j in range(1, c):
                row[j] += row[j - 1]
        
        count = 0
        for c1 in range(c):
            for c2 in range(c1, c):
                sum_map = defaultdict(int)
                sum_map[0] = 1
                curr_sum = 0
                for row in range(r):
                    curr_sum += matrix[row][c2] - (matrix[row][c1 - 1] if c1 > 0 else 0)
                    count += sum_map[curr_sum - target]
                    sum_map[curr_sum] += 1
        return count
