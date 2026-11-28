import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    mid = (len(arr) + 1) // 2
    print(" ".join(map(str, arr[:mid])))
    print(" ".join(map(str, arr[mid:])))
solve()
