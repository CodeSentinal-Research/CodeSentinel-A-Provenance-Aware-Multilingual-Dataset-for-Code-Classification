import sys
import math
def solve():
    r = int(sys.stdin.read().split()[0])
    print(" ".join(str(math.comb(r, i)) for i in range(r + 1)))
solve()
