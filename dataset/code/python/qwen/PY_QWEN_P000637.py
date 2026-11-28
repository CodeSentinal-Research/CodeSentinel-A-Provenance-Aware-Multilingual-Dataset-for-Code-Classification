import sys
from collections import Counter
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    c = Counter(arr)
    print(" ".join(map(str, [x for x in arr if c[x] == 1])))
solve()
