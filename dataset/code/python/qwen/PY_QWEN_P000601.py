import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:int(d[0])+1])), int(d[int(d[0])+1])
    base, rem = divmod(n, k)
    idx = 0
    for i in range(k):
        l = base + (1 if i < rem else 0)
        print(" ".join(map(str, arr[idx:idx+l])) if l else "")
        idx += l
solve()
