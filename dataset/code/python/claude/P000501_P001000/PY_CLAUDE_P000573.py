
from collections import deque
n=int(input());vals=list(map(lambda x: None if x=='null' else int(x),input().split()))
if not vals or vals[0] is None: exit()
q=deque([(0,0)]);res={}
while q:
    idx,lev=q.popleft()
    if idx>=n or vals[idx] is None: continue
    res.setdefault(lev,[]).append(str(vals[idx]))
    q.append((2*idx+1,lev+1));q.append((2*idx+2,lev+1))
for lev in sorted(res):
    row=res[lev]
    print(*(reversed(row) if lev%2==1 else row))
