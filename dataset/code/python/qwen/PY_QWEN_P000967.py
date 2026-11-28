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
    curr_r, curr_m = rems[0], mods[0]
    for i in range(1, n):
        r2, m2 = rems[i], mods[i]
        g, p, q = ext_gcd(curr_m, m2)
        if (r2 - curr_r) % g != 0:
            print(-1)
            return
        lcm = curr_m // g * m2
        curr_r = (curr_r + curr_m * ((r2 - curr_r) // g) * p) % lcm
        curr_m = lcm
    print((curr_r % curr_m + curr_m) % curr_m)
solve()
