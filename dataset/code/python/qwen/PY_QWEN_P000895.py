import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    a, b = int(d[0]), int(d[1])
    print(abs(a * b) // math.gcd(a, b))
solve()
