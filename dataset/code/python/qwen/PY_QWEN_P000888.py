import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    sq = str(n * n)
    print("true" if sq.endswith(str(n)) else "false")
solve()
