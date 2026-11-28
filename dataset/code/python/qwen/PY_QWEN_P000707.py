import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr, op, cl):
        if len(curr) == 2 * n:
            res.append(curr)
            return
        if op < n: rec(curr + "(", op + 1, cl)
        if cl < op: rec(curr + ")", op, cl + 1)
    rec("", 0, 0)
    for x in res: print(x)
solve()
