import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    def rec(k):
        if k == 1: return ["0", "1"]
        prev = rec(k - 1)
        return prev + [x[::-1] for x in prev]
    for x in rec(n): print(x)
solve()
