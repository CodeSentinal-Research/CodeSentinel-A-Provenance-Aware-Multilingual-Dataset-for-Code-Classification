import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    print(" ".join(map(str, [x for x in arr if x % 2 == 0] + [x for x in arr if x % 2 != 0])))
solve()
