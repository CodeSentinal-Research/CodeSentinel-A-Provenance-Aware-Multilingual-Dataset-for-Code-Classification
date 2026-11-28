
from collections import deque
n=int(input());q=deque(map(int,input().split()));k=int(input())
for _ in range(k): q.append(q.popleft())
print(*q)
