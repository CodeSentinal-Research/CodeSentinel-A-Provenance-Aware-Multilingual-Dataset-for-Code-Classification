from typing import List

def matrix_multiplication(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    r1, c1 = len(a), len(a[0])
    r2, c2 = len(b), len(b[0])
    res = [[0] * c2 for _ in range(r1)]
    for i in range(r1):
        for k in range(c1):
            for j in range(c2):
                res[i][j] += a[i][k] * b[k][j]
    return res

if __name__ == '__main__':
    r1, c1 = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(r1)]
    r2, c2 = map(int, input().split())
    b = [list(map(int, input().split())) for _ in range(r2)]
    res = matrix_multiplication(a, b)
    for row in res:
        print(" ".join(map(str, row)))