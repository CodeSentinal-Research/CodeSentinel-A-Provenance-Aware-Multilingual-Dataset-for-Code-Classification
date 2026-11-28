import sys
import heapq
def solve():
    d = sys.stdin.read().split()
    if not d: return
    k = int(d[0])
    idx = 1
    h = []
    for _ in range(k):
        sz = int(d[idx]); idx += 1
        lst = list(map(int, d[idx:idx+sz])); idx += sz
        for x in lst: heapq.heappush(h, x)
    print(" ".join(map(str, [heapq.heappop(h) for _ in range(len(h))])))
solve()
