from typing import List

def matrix_addition(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    r, c = len(a), len(a[0])
    return [[a[i][j] + b[i][j] for j in range(c)] for i in range(r)]

if __name__ == '__main__':
    r, c = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(r)]
    b = [list(map(int, input().split())) for _ in range(r)]
    res = matrix_addition(a, b)
    for row in res:
        print(" ".join(map(str, row)))