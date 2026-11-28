import sys
def solve():
    expr = sys.stdin.read().split()[0]
    def rec(s):
        res = []
        for i in range(len(s)):
            if s[i] in "+-*":
                for l in rec(s[:i]):
                    for r in rec(s[i+1:]):
                        res.append(f"({l}{s[i]}{r})")
        if not res: res.append(s)
        return res
    for x in sorted(set(rec(expr))): print(x)
solve()
