import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    q = deque(list(map(int, input_data[1:n+1])))
    stack = []
    while q:
        stack.append(q.popleft())
    while stack:
        q.append(stack.pop())
    print(" ".join(map(str, q)))
solve()
