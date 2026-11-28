# problem title : Equal Row and Column Pairs
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row_counts = Counter(tuple(row) for row in grid)
        n = len(grid)
        ans = 0

        for c in range(n):
            col = tuple(grid[r][c] for r in range(n))
            ans += row_counts[col]

        return ans
