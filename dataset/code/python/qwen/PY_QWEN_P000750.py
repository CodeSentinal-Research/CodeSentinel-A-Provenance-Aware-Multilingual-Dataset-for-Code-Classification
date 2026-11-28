import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr):
        if curr > N: return
        if curr > 0: res.append(curr)
        for i in range(1 if curr == 0 else 0, 10):
            if curr == 0 and i == 0: continue
            rec(curr * 10 + i)
    rec(0)
    print(" ".join(map(str, sorted(res))))
solve()
