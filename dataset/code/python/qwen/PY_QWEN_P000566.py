import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    start = input_data[0]
    end = input_data[1]
    n = int(input_data[2])
    bank = set(input_data[3:3+n])
    if end not in bank:
        print(-1)
        return
    q = deque([(start, 0)])
    vis = {start}
    while q:
        curr, steps = q.popleft()
        if curr == end:
            print(steps)
            return
        for i in range(8):
            for c in 'ACGT':
                nxt = curr[:i] + c + curr[i+1:]
                if nxt in bank and nxt not in vis:
                    vis.add(nxt)
                    q.append((nxt, steps + 1))
    print(-1)
solve()
