import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    for i in range(len(arr) - 1):
        res.append(arr[i])
        res.append(math.gcd(arr[i], arr[i+1]))
    res.append(arr[-1])
    print(" ".join(map(str, res)))
solve()
