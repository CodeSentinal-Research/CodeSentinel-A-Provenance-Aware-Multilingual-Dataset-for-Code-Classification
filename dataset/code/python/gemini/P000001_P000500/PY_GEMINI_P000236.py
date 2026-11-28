from typing import List

class Solution:
    def findMaxValue(self, mat: List[List[int]], N: int) -> int:
        max_arr = [[0] * N for _ in range(N)]
        max_arr[N - 1][N - 1] = mat[N - 1][N - 1]

        max_v = mat[N - 1][N - 1]
        for j in range(N - 2, -1, -1):
            max_v = max(max_v, mat[N - 1][j])
            max_arr[N - 1][j] = max_v

        max_v = mat[N - 1][N - 1]
        for i in range(N - 2, -1, -1):
            max_v = max(max_v, mat[i][N - 1])
            max_arr[i][N - 1] = max_v

        max_diff = float('-inf')

        for i in range(N - 2, -1, -1):
            for j in range(N - 2, -1, -1):
                max_diff = max(max_diff, max_arr[i + 1][j + 1] - mat[i][j])
                max_arr[i][j] = max(mat[i][j], max(max_arr[i + 1][j], max_arr[i][j + 1]))

        return max_diff