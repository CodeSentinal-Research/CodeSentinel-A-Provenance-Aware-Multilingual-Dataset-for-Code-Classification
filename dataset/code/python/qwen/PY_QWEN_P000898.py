import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    num, den = int(d[0]), int(d[1])
    g = math.gcd(num, den)
    print(num // g, den // g)
solve()
