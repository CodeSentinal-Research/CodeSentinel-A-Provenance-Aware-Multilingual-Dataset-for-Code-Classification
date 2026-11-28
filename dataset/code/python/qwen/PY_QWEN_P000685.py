import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s = d[0]
    print("true" if s == s[::-1] else "false")
solve()
