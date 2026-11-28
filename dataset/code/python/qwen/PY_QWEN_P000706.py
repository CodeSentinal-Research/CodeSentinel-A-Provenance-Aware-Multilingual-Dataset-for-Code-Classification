import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr):
        if len(curr) == n:
            res.append(curr)
            return
        rec(curr + "0")
        rec(curr + "1")
    rec("")
    for x in res: print(x)
solve()
