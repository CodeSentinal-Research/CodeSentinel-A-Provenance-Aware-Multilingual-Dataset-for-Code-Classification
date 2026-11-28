import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    print(math.gcd(int(d[0]), int(d[1])))
solve()
