import math

def calculate_ncr(n: int, r: int) -> int:
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    r = min(r, n - r)
    numer = 1
    denom = 1
    for i in range(1, r + 1):
        numer *= (n - i + 1)
        denom *= i
    return numer // denom

if __name__ == '__main__':
    n, r = map(int, input().split())
    print(calculate_ncr(n, r))