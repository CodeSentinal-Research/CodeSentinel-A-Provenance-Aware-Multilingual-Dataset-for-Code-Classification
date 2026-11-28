import sys
def solve():
    s = sys.stdin.read().split()[0]
    res = []
    def rec(i, curr):
        if i == len(s):
            res.append(curr)
            return
        rec(i + 1, curr)
        rec(i + 1, curr + s[i])
    rec(0, "")
    for x in sorted(res): print(x)
solve()
