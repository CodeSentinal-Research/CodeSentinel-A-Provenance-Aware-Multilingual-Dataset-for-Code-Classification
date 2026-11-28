import sys
import math
def solve():
    d = sys.stdin.read().split()
    x1, y1, x2, y2 = int(d[0]), int(d[1]), int(d[2]), int(d[3])
    print(math.sqrt((x2 - x1)**2 + (y2 - y1)**2))
solve()
