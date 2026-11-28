import sys
def solve():
    d = sys.stdin.read().split()
    n, l, r = int(d[0]), int(d[1]), int(d[2])
    factors = []
    temp = n
    p = 2
    while p * p <= temp:
        if temp % p == 0:
            factors.append(p)
            while temp % p == 0:
                temp //= p
        p += 1
    if temp > 1:
        factors.append(temp)
    def count_coprime(x):
        if x < 0: return 0
        res = 0
        m = len(factors)
        for i in range(1 << m):
            prod = 1
            bits = 0
            for j in range(m):
                if (i & (1 << j)):
                    prod *= factors[j]
                    bits += 1
            cnt = x // prod
            if bits % 2 == 0:
                res += cnt
            else:
                res -= cnt
        return res
    print(count_coprime(r) - count_coprime(l - 1))
solve()
