import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    curr = sum(arr[:k])
    mx = curr
    for i in range(k, n):
        curr += arr[i] - arr[i-k]
        mx = max(mx, curr)
    print(mx / k)
solve()
