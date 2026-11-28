
from collections import deque
n=int(input());k=int(input());q=deque(range(1,n+1))
while len(q)>1:
    for _ in range(k-1): q.append(q.popleft())
    q.popleft()
print(q[0])
