import sys
def solve():
    expr = sys.stdin.read().split()[0]
    def rec(s):
        res = []
        for i in range(len(s)):
            if s[i] in "+-*":
                for l in rec(s[:i]):
                    for r in rec(s[i+1:]):
                        if s[i] == '+': res.append(l + r)
                        elif s[i] == '-': res.append(l - r)
                        else: res.append(l * r)
        if not res: res.append(int(s))
        return res
    print(" ".join(map(str, sorted(rec(expr)))))
solve()
