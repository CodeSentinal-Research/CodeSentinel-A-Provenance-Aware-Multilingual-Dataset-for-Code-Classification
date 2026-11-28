from typing import List

class Solution:
    def optimalSearchTree(self, p: List[float], q: List[float], n: int) -> float:
        """Performs search to locate target element within the given collection."""
        e = [[0.0] * (n + 2) for _ in range(n + 2)]
        w = [[0.0] * (n + 2) for _ in range(n + 2)]

        for i in range(1, n + 2):
            e[i][i - 1] = q[i - 1]
            w[i][i - 1] = q[i - 1]

        for length in range(1, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                e[i][j] = float('inf')
                w[i][j] = w[i][j - 1] + p[j - 1] + q[j]
                for r in range(i, j + 1):
                    t = e[i][r - 1] + e[r + 1][j] + w[i][j]
                    if t < e[i][j]:
                        e[i][j] = t

        return e[1][n]