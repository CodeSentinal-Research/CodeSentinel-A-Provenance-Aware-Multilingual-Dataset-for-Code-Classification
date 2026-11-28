from typing import List

class Solution:
    def optimalRoot(self, keys: List[int], freq: List[int]) -> int:
        n = len(keys)
        cost = [[0] * n for _ in range(n)]
        root_choice = [[0] * n for _ in range(n)]

        w = [[0] * n for _ in range(n)]
        for i in range(n):
            w[i][i] = freq[i]
            cost[i][i] = freq[i]
            root_choice[i][i] = i
            for j in range(i + 1, n):
                w[i][j] = w[i][j - 1] + freq[j]

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                cost[i][j] = float('inf')
                for r in range(i, j + 1):
                    c = (cost[i][r - 1] if r > i else 0) + (cost[r + 1][j] if r < j else 0) + w[i][j]
                    if c < cost[i][j]:
                        cost[i][j] = c
                        root_choice[i][j] = r

        return keys[root_choice[0][n - 1]]