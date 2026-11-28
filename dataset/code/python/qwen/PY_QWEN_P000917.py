import sys
import math
def solve():
    d = sys.stdin.read().split()
    n, k = int(d[0]), int(d[1])
    print(math.comb(n + k - 1, k - 1))
solve()
