import sys
from collections import defaultdict
def solve():
    s = sys.stdin.read().split()[0]
    vowels = set("aeiou")
    pref = defaultdict(int)
    pref[0] = 1
    curr = 0
    ans = 0
    for c in s:
        if c in vowels: curr += 1
        else: curr -= 1
        ans += pref[curr]
        pref[curr] += 1
    print(ans)
solve()
