import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    x, n = int(d[0]), int(d[1])
    print(x ** n)
solve()
