import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr, last):
        if len(curr) == N:
            res.append(curr)
            return
        rec(curr + "0", 0)
        if last == 0: rec(curr + "1", 1)
    rec("", 0)
    for x in res: print(x)
solve()
