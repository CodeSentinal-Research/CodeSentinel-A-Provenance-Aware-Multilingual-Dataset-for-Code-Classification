import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    res = 0
    def rec(idx, mask):
        nonlocal res
        if idx > N:
            res += 1
            return
        for i in range(1, N + 1):
            if not (mask & (1 << i)):
                if i % idx == 0 or idx % i == 0:
                    rec(idx + 1, mask | (1 << i))
    rec(1, 0)
    print(res)
solve()
