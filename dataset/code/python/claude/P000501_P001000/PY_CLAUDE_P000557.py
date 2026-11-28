
from collections import deque
target=int(input())
q=deque([(0,1,0)]);visited={(0,1)}
while q:
    pos,spd,steps=q.popleft()
    for npos,nspd in [(pos+spd,spd*2),(pos,(-1 if spd>0 else 1))]:
        if npos==target: print(steps+1);exit()
        if -target<npos<2*target and (npos,nspd) not in visited:
            visited.add((npos,nspd));q.append((npos,nspd,steps+1))
print(-1)
