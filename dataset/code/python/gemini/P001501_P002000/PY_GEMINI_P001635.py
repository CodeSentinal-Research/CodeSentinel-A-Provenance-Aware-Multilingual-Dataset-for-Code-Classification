from typing import List
from collections import defaultdict

def count_equal_zeros_ones_submatrices(mat: List[List[int]]) -> int:
    m, n = len(mat), len(mat[0])
    ans = 0

    for l in range(n):
        row_diff = [0] * m
        for r in range(l, n):
            for i in range(m):
                row_diff[i] += 1 if mat[i][r] == 1 else -1

            count = defaultdict(int)
            count[0] = 1
            cur = 0
            for i in range(m):
                cur += row_diff[i]
                ans += count[cur]
                count[cur] += 1

    return ans

if __name__ == '__main__':
    m, n = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(m)]
    print(count_equal_zeros_ones_submatrices(mat))