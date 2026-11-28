from typing import List

def max_sum_rectangle(mat: List[List[int]]) -> int:
    m, n = len(mat), len(mat[0])
    max_sum = float('-inf')

    for left in range(n):
        row_sum = [0] * m
        for right in range(left, n):
            for i in range(m):
                row_sum[i] += mat[i][right]

            cur_max = row_sum[0]
            cur_sum = 0
            for x in row_sum:
                cur_sum = max(x, cur_sum + x)
                cur_max = max(cur_max, cur_sum)

            max_sum = max(max_sum, cur_max)

    return max_sum

if __name__ == '__main__':
    m, n = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(m)]
    print(max_sum_rectangle(mat))