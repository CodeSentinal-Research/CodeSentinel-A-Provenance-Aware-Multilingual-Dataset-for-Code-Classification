from typing import List

def largest_square_sum_le_k(mat: List[List[int]], k: int) -> int:
    m, n = len(mat), len(mat[0])
    p = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m):
        for j in range(n):
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j]

    max_side = 0
    for side in range(1, min(m, n) + 1):
        for i in range(m - side + 1):
            for j in range(n - side + 1):
                sum_sq = p[i + side][j + side] - p[i][j + side] - p[i + side][j] + p[i][j]
                if sum_sq <= k:
                    max_side = max(max_side, side)
    return max_side

if __name__ == '__main__':
    m, n, k = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(m)]
    print(largest_square_sum_le_k(mat, k))