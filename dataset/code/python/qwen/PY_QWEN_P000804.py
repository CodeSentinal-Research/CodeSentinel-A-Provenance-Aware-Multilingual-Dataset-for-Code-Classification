import sys
from collections import defaultdict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    K = int(d[n+1])
    pref = defaultdict(int)
    pref[0] = 1
    curr = 0
    ans = 0
    for x in nums:
        curr ^= x
        ans += pref[curr ^ K]
        pref[curr] += 1
    print(ans)
solve()
