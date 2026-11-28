def nCr(n: int, r: int) -> int:
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    r = min(r, n - r)
    ans = 1
    for i in range(1, r + 1):
        ans = ans * (n - i + 1) // i
    return ans

if __name__ == '__main__':
    n, r = map(int, input().split())
    print(nCr(n, r))