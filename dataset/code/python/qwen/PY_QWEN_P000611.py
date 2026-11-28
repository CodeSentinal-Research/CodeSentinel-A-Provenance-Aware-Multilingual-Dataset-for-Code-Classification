import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    n = len(arr)
    print(max(arr[i] + arr[n - 1 - i] for i in range(n // 2)))
solve()
