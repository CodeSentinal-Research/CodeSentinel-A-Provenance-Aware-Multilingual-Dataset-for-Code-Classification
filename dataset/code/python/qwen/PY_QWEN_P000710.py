import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    res = []
    def rec(curr, used):
        if len(curr) == n:
            res.append(curr[:])
            return
        for i in range(n):
            if not used[i]:
                used[i] = True
                curr.append(arr[i])
                rec(curr, used)
                curr.pop()
                used[i] = False
    rec([], [False] * n)
    for x in res: print(" ".join(map(str, x)))
solve()
