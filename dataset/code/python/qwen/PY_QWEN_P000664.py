import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    print(" ".join(map(str, [arr[i] for i in range(len(arr)) if i % 2 == 0])))
solve()
