import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            res.append(d)
            while n % d == 0:
                n //= d
        d += 1
    if n > 1:
        res.append(n)
    print(" ".join(map(str, res)))
solve()
