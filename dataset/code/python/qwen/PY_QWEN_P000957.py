import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    a, b, x, y = int(d[0]), int(d[1]), int(d[2]), int(d[3])
    g, _, _ = ext_gcd(a, b)
    print("true" if a * x + b * y == g else "false")
solve()
