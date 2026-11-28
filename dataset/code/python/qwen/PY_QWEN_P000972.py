import sys
import math
def solve():
    d = sys.stdin.read().split()
    n, k = int(d[0]), int(d[1])
    prob = math.comb(n, k) * (0.5 ** n)
    print(prob)
solve()
