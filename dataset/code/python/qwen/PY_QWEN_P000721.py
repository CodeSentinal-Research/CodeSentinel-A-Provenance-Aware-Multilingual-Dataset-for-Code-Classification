import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    res = []
    def rec(idx, curr):
        if len(curr) >= 2:
            res.append(curr[:])
        for i in range(idx, n):
            if curr and arr[i] < curr[-1]: continue
            if curr and arr[i] == curr[-1] and i > idx and arr[i-1] == arr[i]: continue
            curr.append(arr[i])
            rec(i + 1, curr)
            curr.pop()
    rec(0, [])
    for x in sorted(set(tuple(y) for y in res)): print(" ".join(map(str, x)))
solve()
