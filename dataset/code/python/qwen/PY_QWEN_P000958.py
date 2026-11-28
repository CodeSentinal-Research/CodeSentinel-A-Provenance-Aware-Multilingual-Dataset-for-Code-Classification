import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    a, b = int(d[0]), int(d[1])
    g, x, y = ext_gcd(a, b)
    x = (x % (b // g) + (b // g)) % (b // g)
    if x == 0: x += b // g
    y = (g - a * x) // b
    print(x, y)
solve()
