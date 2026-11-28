import sys
def solve():
    expr = sys.stdin.read().split()[0]
    def rec(l, r):
        if l > r: return 0, 0
        if l == r: return (1, 0) if expr[l] == 'T' else (0, 1)
        t, f = 0, 0
        for i in range(l + 1, r, 2):
            lt, lf = rec(l, i - 1)
            rt, rf = rec(i + 1, r)
            if expr[i] == '&': t += lt * rt; f += (lt + lf) * (rt + rf) - lt * rt
            elif expr[i] == '|': t += (lt + lf) * (rt + rf) - lf * rf; f += lf * rf
            else: t += lt * rf + lf * rt; f += lt * rt + lf * rf
        return t, f
    print(rec(0, len(expr) - 1)[0])
solve()
