import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    q = deque(list(map(int, input_data[1:n+1])))
    k = int(input_data[n+1])
    stack = []
    for _ in range(k):
        stack.append(q.popleft())
    while stack:
        q.appendleft(stack.pop())
    print(" ".join(map(str, q)))
solve()
