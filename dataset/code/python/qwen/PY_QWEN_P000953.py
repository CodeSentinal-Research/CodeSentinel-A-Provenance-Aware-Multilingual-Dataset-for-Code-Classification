import sys
def solve():
    d = sys.stdin.read().split()
    a, n = int(d[0]), int(d[1])
    res = n
    temp = n
    p = 2
    while p * p <= temp:
        if temp % p == 0:
            while temp % p == 0:
                temp //= p
            res -= res // p
        p += 1
    if temp > 1:
        res -= res // temp
    print(pow(a, res, n))
solve()
