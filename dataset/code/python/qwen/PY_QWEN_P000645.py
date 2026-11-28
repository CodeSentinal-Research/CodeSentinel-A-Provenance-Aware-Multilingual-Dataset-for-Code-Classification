import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    for i in range(0, len(arr) - 1, 2):
        arr[i], arr[i+1] = arr[i+1], arr[i]
    print(" ".join(map(str, arr)))
solve()
