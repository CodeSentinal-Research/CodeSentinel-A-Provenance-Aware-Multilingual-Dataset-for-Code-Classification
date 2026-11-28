import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    b, e, m = int(d[0]), int(d[1]), int(d[2])
    print(pow(b, e, m))
solve()
