import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    rems = list(map(int, d[1:n+1]))
    mods = list(map(int, d[n+1:2*n+1]))
    M = 1
    for m in mods: M *= m
    res = 0
    for r, m in zip(rems, mods):
        Mi = M // m
        _, inv, _ = ext_gcd(Mi, m)
        res = (res + r * Mi * inv) % M
    print((res % M + M) % M)
solve()
