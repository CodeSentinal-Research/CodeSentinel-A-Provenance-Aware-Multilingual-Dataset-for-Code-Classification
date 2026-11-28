from typing import List

MOD = 10**9 + 7

def mat_mul(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    n = len(a)
    res = [[0] * n for _ in range(n)]
    for i in range(n):
        for k in range(n):
            for j in range(n):
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD
    return res

def mat_pow(mat: List[List[int]], p: int) -> List[List[int]]:
    """Calculates modular exponentiation (base^exp % mod) efficiently."""
    n = len(mat)
    res = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    base = mat
    while p > 0:
        # If current bit is set, multiply base into result
        if p % 2 == 1:
            res = mat_mul(res, base)
        base = mat_mul(base, base)
        p //= 2
    return res

if __name__ == '__main__':
    n, p = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(n)]
    ans = mat_pow(mat, p)
    for row in ans:
        print(" ".join(map(str, row)))