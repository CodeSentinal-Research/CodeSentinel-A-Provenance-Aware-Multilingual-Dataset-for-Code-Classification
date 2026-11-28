import sys
def solve():
    s = sys.stdin.read().split()[0]
    res = []
    def rec(curr, used):
        if len(curr) == len(s):
            res.append(curr)
            return
        for i in range(len(s)):
            if not used[i]:
                used[i] = True
                rec(curr + s[i], used)
                used[i] = False
    rec("", [False] * len(s))
    for x in sorted(res): print(x)
solve()
