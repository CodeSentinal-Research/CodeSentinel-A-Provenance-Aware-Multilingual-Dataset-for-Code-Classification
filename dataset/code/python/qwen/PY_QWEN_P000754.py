import sys
def solve():
    s = sys.stdin.read().split()[0]
    res = []
    def rec(idx, curr):
        if idx == len(s):
            res.append(curr)
            return
        if s[idx].isalpha():
            rec(idx + 1, curr + s[idx].lower())
            rec(idx + 1, curr + s[idx].upper())
        else:
            rec(idx + 1, curr + s[idx])
    rec(0, "")
    for x in sorted(res): print(x)
solve()
