import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    MOD = 10**9 + 7
    def rec(b, e):
        if e == 0: return 1
        h = rec(b, e // 2)
        h = (h * h) % MOD
        if e % 2 == 1: h = (h * b) % MOD
        return h
    ans = (rec(5, (N + 1) // 2) * rec(4, N // 2)) % MOD
    print(ans)
solve()
