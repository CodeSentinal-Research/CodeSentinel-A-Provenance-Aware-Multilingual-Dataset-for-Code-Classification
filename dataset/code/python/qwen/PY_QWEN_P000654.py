import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    piv = arr[-1]
    print(" ".join(map(str, [x for x in arr[:-1] if x < piv] + [piv] + [x for x in arr[:-1] if x >= piv])))
solve()
