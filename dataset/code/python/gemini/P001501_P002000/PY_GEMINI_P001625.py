from typing import List

def construct_2d_prefix(mat: List[List[int]]) -> List[List[int]]:
    m, n = len(mat), len(mat[0])
    p = [[0] * n for _ in range(m)]

    for i in range(m):
        for j in range(n):
            p[i][j] = mat[i][j]
            if i > 0: p[i][j] += p[i - 1][j]
            if j > 0: p[i][j] += p[i][j - 1]
            if i > 0 and j > 0: p[i][j] -= p[i - 1][j - 1]

    return p

if __name__ == '__main__':
    m, n = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(m)]
    res = construct_2d_prefix(mat)
    for row in res:
        print(*row)