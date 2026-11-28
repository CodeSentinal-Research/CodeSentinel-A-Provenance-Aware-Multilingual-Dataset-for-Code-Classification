import sys
import heapq
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    print(" ".join(map(str, sorted(arr))))
solve()
