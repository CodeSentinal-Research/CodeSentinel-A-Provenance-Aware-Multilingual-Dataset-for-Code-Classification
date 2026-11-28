import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    start, goal = int(d[0]), int(d[1])
    print(bin(start ^ goal).count('1'))
solve()
