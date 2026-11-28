import sys
def solve():
    s = sys.stdin.read().split()[0]
    res = []
    def rec(idx, curr):
        if idx == len(s):
            res.append(curr[:])
            return
        for i in range(idx + 1, len(s) + 1):
            sub = s[idx:i]
            if sub == sub[::-1]:
                curr.append(sub)
                rec(i, curr)
                curr.pop()
    rec(0, [])
    for x in res: print(" ".join(x))
solve()
