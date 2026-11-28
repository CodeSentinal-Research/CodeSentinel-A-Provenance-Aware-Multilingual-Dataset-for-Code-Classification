import sys
import math
def solve():
    d = sys.stdin.read().split()
    n, r = int(d[0]), int(d[1])
    print(math.perm(n, r))
solve()
