import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    print("true" if n % 3 == 0 else "false")
solve()
