import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    res = 0
    for x in nums:
        res ^= x
    print(res)
solve()
