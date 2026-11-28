import sys
def solve():
    d = sys.stdin.read().split()
    a, b = int(d[0]), int(d[1])
    print(a * b - a - b)
solve()
