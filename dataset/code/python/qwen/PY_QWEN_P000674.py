import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    arr.sort()
    res = [0] * len(arr)
    l, r = 0, len(arr) - 1
    for i in range(len(arr)):
        if i % 2 == 0: res[i] = arr[l]; l += 1
        else: res[i] = arr[r]; r -= 1
    print(" ".join(map(str, res)))
solve()
