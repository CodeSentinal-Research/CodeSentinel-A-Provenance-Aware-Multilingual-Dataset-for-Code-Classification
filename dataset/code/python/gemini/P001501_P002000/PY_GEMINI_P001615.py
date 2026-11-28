from typing import List
from collections import defaultdict

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0

        for row in matrix:
            for j in range(1, n):
                row[j] += row[j - 1]

        for c1 in range(n):
            for c2 in range(c1, n):
                count = defaultdict(int)
                count[0] = 1
                cur = 0
                for r in range(m):
                    cur += matrix[r][c2] - (matrix[r][c1 - 1] if c1 > 0 else 0)
                    ans += count[cur - target]
                    count[cur] += 1

        return ans