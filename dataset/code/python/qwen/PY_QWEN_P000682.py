import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    print(math.factorial(n))
solve()
