import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:-1]))
    val = int(d[-1])
    if not arr:
        print(val)
    else:
        arr.append(val)
        arr.sort()
        print(" ".join(map(str, arr)))
solve()
