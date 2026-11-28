import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    a, b, m = int(d[0]), int(d[1]), int(d[2])
    g, x, y = ext_gcd(a, m)
    if b % g != 0:
        print(-1)
    else:
        x0 = (x * (b // g)) % m
        print((x0 + m) % m)
solve()
