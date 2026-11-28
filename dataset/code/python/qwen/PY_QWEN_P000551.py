import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    q = deque(["1"])
    res = []
    for _ in range(n):
        curr = q.popleft()
        res.append(curr)
        q.append(curr + "0")
        q.append(curr + "1")
    print(" ".join(res))
solve()
