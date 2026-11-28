import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s, t = d[0], d[1]
    def rec(i, j):
        if j == len(t): return 1
        if i == len(s): return 0
        ans = rec(i + 1, j)
        if s[i] == t[j]: ans += rec(i + 1, j + 1)
        return ans
    print(rec(0, 0))
solve()
