import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s, p = d[0], d[1]
    def rec(i, j):
        if j == len(p): return i == len(s)
        fm = j + 1 < len(p) and p[j+1] == '*'
        if fm:
            if rec(i, j + 2): return True
            if i < len(s) and (p[j] == '.' or p[j] == s[i]): return rec(i + 1, j + 2)
        else:
            if i < len(s) and (p[j] == '.' or p[j] == s[i]): return rec(i + 1, j + 1)
        return False
    print("true" if rec(0, 0) else "false")
solve()
