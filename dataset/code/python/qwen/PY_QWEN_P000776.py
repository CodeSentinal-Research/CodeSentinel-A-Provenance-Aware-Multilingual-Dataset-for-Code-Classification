import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s, m = d[0], int(d[1])
    words = set(d[2:2+m])
    res = []
    def rec(idx, curr):
        if idx == len(s):
            res.append(curr[:])
            return
        for i in range(idx + 1, len(s) + 1):
            if s[idx:i] in words:
                curr.append(s[idx:i])
                rec(i, curr)
                curr.pop()
    rec(0, [])
    for x in sorted(res): print(" ".join(x))
solve()
