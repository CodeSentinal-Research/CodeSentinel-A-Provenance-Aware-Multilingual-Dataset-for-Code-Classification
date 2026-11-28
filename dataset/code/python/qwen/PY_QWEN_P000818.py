import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, target = int(d[0]), int(d[1])
    nums = list(map(int, d[2:2+n]))
    print("true" if target in nums else "false")
solve()
