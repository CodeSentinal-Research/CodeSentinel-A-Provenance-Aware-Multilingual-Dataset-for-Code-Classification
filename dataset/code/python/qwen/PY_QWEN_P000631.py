import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, t = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    print("true" if t in arr else "false")
solve()
