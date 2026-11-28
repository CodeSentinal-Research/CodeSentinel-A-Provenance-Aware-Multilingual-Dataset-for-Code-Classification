import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    pref = {}
    pref[0] = -1
    curr = 0
    ans = 0
    for i, x in enumerate(nums):
        if x > 0: curr += 1
        else: curr -= 1
        if curr in pref:
            ans = max(ans, i - pref[curr])
        else:
            pref[curr] = i
    print(ans)
solve()
