import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    times = list(map(int, input_data[1:n+1]))
    q = deque()
    for t in times:
        while q and q[0] <= t - 3000:
            q.popleft()
        q.append(t)
        print(len(q))
solve()
