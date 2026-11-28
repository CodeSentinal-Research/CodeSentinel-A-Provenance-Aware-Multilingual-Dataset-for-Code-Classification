import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    print(d[0][::-1])
solve()
