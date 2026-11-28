import sys
def solve():
    expr = sys.stdin.read().split()[0]
    def rec(l, r):
        if l > r: return []
        if l == r: return [int(expr[l])]
        res = []
        for i in range(l + 1, r, 2):
            for left in rec(l, i - 1):
                for right in rec(i + 1, r):
                    if expr[i] == '+': res.append(left + right)
                    elif expr[i] == '-': res.append(left - right)
                    else: res.append(left * right)
        return res
    vals = rec(0, len(expr) - 1)
    mx = max(vals)
    print(sum(1 for v in vals if v == mx))
solve()
