import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    d = int(input_data[0])
    deadends = set(input_data[1:d+1])
    target = input_data[d+1]
    if "0000" in deadends:
        print(-1)
        return
    q = deque([("0000", 0)])
    vis = {"0000"}
    while q:
        curr, steps = q.popleft()
        if curr == target:
            print(steps)
            return
        for i in range(4):
            for move in [-1, 1]:
                nxt = curr[:i] + str((int(curr[i]) + move) % 10) + curr[i+1:]
                if nxt not in vis and nxt not in deadends:
                    vis.add(nxt)
                    q.append((nxt, steps + 1))
    print(-1)
solve()
