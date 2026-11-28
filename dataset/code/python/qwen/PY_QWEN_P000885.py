import sys
def solve():
    n = sys.stdin.read().split()[0]
    p = len(n)
    s = sum(int(c) ** p for c in n)
    print("true" if s == int(n) else "false")
solve()
