import sys
import math
def solve():
    n = int(sys.stdin.read().split()[0])
    print(math.factorial(n - 1))
solve()
