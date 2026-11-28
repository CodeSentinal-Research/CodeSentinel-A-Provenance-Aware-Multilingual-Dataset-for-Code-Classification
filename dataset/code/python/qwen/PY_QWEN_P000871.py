import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    left, right = int(d[0]), int(d[1])
    shift = 0
    while left < right:
        left >>= 1
        right >>= 1
        shift += 1
    print(left << shift)
solve()
