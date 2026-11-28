
from collections import deque
n=int(input());rooms=[]
for _ in range(n):
    k=int(input());rooms.append(list(map(int,input().split())) if k>0 else [])
visited={0};q=deque([0])
while q:
    r=q.popleft()
    for key in rooms[r]:
        if key not in visited: visited.add(key);q.append(key)
print('true' if len(visited)==n else 'false')
