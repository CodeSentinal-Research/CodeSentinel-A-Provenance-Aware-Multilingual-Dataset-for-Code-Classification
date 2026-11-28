import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    odd = [arr[i] for i in range(0, len(arr), 2)]
    even = [arr[i] for i in range(1, len(arr), 2)][::-1]
    res = []
    for i in range(len(odd)):
        res.append(odd[i])
        if i < len(even): res.append(even[i])
    print(" ".join(map(str, res)))
solve()
