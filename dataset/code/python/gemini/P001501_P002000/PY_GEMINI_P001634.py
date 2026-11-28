from typing import List

class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        max_sum = float('-inf')

        for l in range(n):
            row_sum = [0] * m
            for r in range(l, n):
                for i in range(m):
                    row_sum[i] += matrix[i][r]

                for i in range(m):
                    cur = 0
                    for j in range(i, m):
                        cur += row_sum[j]
                        if cur <= k:
                            max_sum = max(max_sum, cur)

        return max_sum