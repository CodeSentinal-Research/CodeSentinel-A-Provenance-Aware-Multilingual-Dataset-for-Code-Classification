import sys
def solve():
    d = sys.stdin.read().split()
    x1, y1 = int(d[0]), int(d[1])
    x2, y2 = int(d[2]), int(d[3])
    x3, y3 = int(d[4]), int(d[5])
    cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
    print("true" if cross == 0 else "false")
solve()
