import sys
def solve():
    d = sys.stdin.read().split()
    x1, y1, x2, y2 = int(d[0]), int(d[1]), int(d[2]), int(d[3])
    print((x1 + x2) / 2.0, (y1 + y2) / 2.0)
solve()
