def nPr(n: int, r: int) -> int:
    if r < 0 or r > n:
        return 0
    ans = 1
    for i in range(r):
        ans *= (n - i)
    return ans

if __name__ == '__main__':
    n, r = map(int, input().split())
    print(nPr(n, r))