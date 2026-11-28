import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    arr.sort()
    res = []
    def rec(idx, curr, rem):
        if rem == 0:
            res.append(curr[:])
            return
        for i in range(idx, n):
            if i > idx and arr[i] == arr[i-1]: continue
            if arr[i] > rem: break
            curr.append(arr[i])
            rec(i + 1, curr, rem - arr[i])
            curr.pop()
    rec(0, [], target)
    for x in res: print(" ".join(map(str, x)))
solve()
