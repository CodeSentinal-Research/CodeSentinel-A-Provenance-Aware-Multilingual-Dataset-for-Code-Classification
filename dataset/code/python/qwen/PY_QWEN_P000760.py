import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr, last):
        if len(curr) == N:
            res.append(int(curr))
            return
        for i in range(last + 1, 10):
            rec(curr + str(i), i)
    for i in range(1, 10): rec(str(i), i)
    for x in sorted(res): print(x)
solve()
