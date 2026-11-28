
from collections import deque
n=int(input());q=deque(map(int,input().split()));k=int(input())
stk=[q.popleft() for _ in range(k)]
while stk: q.appendleft(stk.pop()) if False else None
newq=deque(reversed(stk))
for _ in range(n-k): newq.append(q.popleft())
print(*newq)
