import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    q = deque(list(map(int, input_data[1:n+1])))
    half = []
    for _ in range(n // 2):
        half.append(q.popleft())
    res = []
    while half:
        res.append(half.pop(0))
        res.append(q.popleft())
    print(" ".join(map(str, res)))
solve()
