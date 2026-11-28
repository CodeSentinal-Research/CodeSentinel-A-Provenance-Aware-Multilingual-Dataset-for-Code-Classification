import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    s = sum(int(c) for c in str(n))
    print("true" if n % s == 0 else "false")
solve()
