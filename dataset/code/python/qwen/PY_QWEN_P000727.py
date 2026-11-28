import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s, m = d[0], int(d[1])
    words = set(d[2:2+m])
    memo = {}
    def rec(idx):
        if idx == len(s): return [""]
        if idx in memo: return memo[idx]
        res = []
        for i in range(idx + 1, len(s) + 1):
            if s[idx:i] in words:
                for suff in rec(i):
                    res.append(s[idx:i] + (" " + suff if suff else ""))
        memo[idx] = res
        return res
    for x in rec(0): print(x)
solve()
