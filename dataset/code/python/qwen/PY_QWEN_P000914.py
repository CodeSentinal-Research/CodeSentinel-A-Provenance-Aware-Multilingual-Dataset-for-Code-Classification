import sys
import math
def solve():
    d = sys.stdin.read().split()
    m, n = int(d[0]), int(d[1])
    print(math.comb(m + n - 2, m - 1))
solve()
