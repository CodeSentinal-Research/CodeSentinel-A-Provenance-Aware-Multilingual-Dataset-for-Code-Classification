import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    arr.sort()
    res = []
    def rec(idx, curr):
        res.append(curr[:])
        for i in range(idx, n):
            if i > idx and arr[i] == arr[i-1]: continue
            curr.append(arr[i])
            rec(i + 1, curr)
            curr.pop()
    rec(0, [])
    for x in res: print(" ".join(map(str, x)))
solve()
