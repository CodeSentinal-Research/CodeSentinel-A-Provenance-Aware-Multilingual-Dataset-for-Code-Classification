import sys
from collections import deque
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    dq = deque()
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "insertFront": dq.appendleft(int(d[idx])); idx += 1
        elif op == "insertLast": dq.append(int(d[idx])); idx += 1
        elif op == "deleteFront": print(dq.popleft() if dq else -1)
        elif op == "deleteLast": print(dq.pop() if dq else -1)
        elif op == "getFront": print(dq[0] if dq else -1)
        elif op == "getRear": print(dq[-1] if dq else -1)
        elif op == "isEmpty": print("true" if not dq else "false")
        elif op == "size": print(len(dq))
solve()
