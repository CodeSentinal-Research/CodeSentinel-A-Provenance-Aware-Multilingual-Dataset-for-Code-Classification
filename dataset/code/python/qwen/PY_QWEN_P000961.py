import sys
def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def solve():
    d = sys.stdin.read().split()
    a, b, c = int(d[0]), int(d[1]), int(d[2])
    x_min, x_max = int(d[3]), int(d[4])
    y_min, y_max = int(d[5]), int(d[6])
    g, x0, y0 = ext_gcd(a, b)
    if c % g != 0:
        print(0)
        return
    x0 *= c // g
    y0 *= c // g
    dx = b // g
    dy = a // g
    k_min_x = (x_min - x0) / dx if dx > 0 else (x_max - x0) / dx
    k_max_x = (x_max - x0) / dx if dx > 0 else (x_min - x0) / dx
    import math
    k1 = math.ceil(k_min_x)
    k2 = math.floor(k_max_x)
    k_min_y = (y0 - y_max) / dy if dy > 0 else (y0 - y_min) / dy
    k_max_y = (y0 - y_min) / dy if dy > 0 else (y0 - y_max) / dy
    k3 = math.ceil(k_min_y)
    k4 = math.floor(k_max_y)
    ans = max(0, min(k2, k4) - max(k1, k3) + 1)
    print(ans)
solve()
