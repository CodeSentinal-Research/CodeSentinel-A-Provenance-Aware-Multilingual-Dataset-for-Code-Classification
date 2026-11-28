import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    s = sum(int(c) for c in str(n * n))
    print("true" if s == n else "false")
solve()
