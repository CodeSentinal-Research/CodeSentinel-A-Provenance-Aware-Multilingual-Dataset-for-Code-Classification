
from collections import deque
q=int(input());queue=deque()
for _ in range(q):
    t=int(input())
    queue.append(t)
    while queue[0]<t-3000: queue.popleft()
    print(len(queue))
