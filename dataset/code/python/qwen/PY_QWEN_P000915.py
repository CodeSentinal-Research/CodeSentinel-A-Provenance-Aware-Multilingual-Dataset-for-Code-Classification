import sys
import math
def solve():
    n = int(sys.stdin.read().split()[0])
    print(math.comb(2 * n, n) // (n + 1))
solve()
