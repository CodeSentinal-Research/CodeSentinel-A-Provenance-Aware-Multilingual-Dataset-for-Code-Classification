import sys
def solve():
    s = sys.stdin.read().split()[0]
    res = []
    def rec(idx, curr):
        if len(curr) == 4:
            if idx == len(s): res.append(".".join(curr))
            return
        for i in range(1, 4):
            if idx + i > len(s): break
            seg = s[idx:idx+i]
            if (len(seg) > 1 and seg[0] == '0') or int(seg) > 255: continue
            curr.append(seg)
            rec(idx + i, curr)
            curr.pop()
    rec(0, [])
    for x in res: print(x)
solve()
