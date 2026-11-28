import sys
def solve():
    d = sys.stdin.read().split()
    a, b, m = int(d[0]), int(d[1]), int(d[2])
    print(pow(a, b, m))
solve()
