
from collections import deque
n=int(input());vals=list(map(lambda x: None if x=='null' else int(x),input().split()))
if not vals or vals[0] is None: exit()
nodes=list(range(n));q=deque([0]);level=[0]*n;i=1
while q and i<n:
    node=q.popleft()
    if i<n and vals[i] is not None: q.append(i);i+=1
    else: i+=1
    if i<n and vals[i] is not None: q.append(i);i+=1
    else: i+=1

q=deque([(0,0)]);res={}
while q:
    idx,lev=q.popleft()
    if vals[idx] is None: continue
    res.setdefault(lev,[]).append(str(vals[idx]))
    l,r=2*idx+1,2*idx+2
    if l<n: q.append((l,lev+1))
    if r<n: q.append((r,lev+1))
for lev in sorted(res): print(*res[lev])
