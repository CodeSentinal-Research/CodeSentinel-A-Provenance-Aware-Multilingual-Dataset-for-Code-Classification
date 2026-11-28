import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    res = []
    l, r = 0, n - 1
    while l <= r:
        res.append(arr[l])
        if l != r: res.append(arr[r])
        l += 1
        r -= 1
    print(" ".join(map(str, res)))
solve()
