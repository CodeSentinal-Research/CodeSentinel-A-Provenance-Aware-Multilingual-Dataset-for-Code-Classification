import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    a, m, b, n = int(d[0]), int(d[1]), int(d[2]), int(d[3])
    g, p, q = ext_gcd(m, n)
    if (b - a) % g != 0:
        print(-1)
        return
    lcm = m // g * n
    res = (a + m * ((b - a) // g) * p) % lcm
    print((res % lcm + lcm) % lcm)
solve()
