import sys
def solve():
    d = sys.stdin.read().split()
    n, r, p = int(d[0]), int(d[1]), int(d[2])
    if r < 0 or r > n:
        print(0)
        return
    num = 1
    den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    print((num * pow(den, -1, p)) % p)
solve()
