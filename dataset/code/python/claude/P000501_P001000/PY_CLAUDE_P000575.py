
from collections import deque
n=int(input());vals=list(map(lambda x: None if x=='null' else int(x),input().split()))
if not vals or vals[0] is None: print(0);exit()
q=deque([(0,0,0)]);mx=0
while q:
    idx,pos,lev=q.popleft();first_pos=pos;last_pos=pos
    while q and q[0][2]==lev: idx2,pos2,lev2=q.popleft();last_pos=pos2
    mx=max(mx,last_pos-first_pos+1)

    if idx<n and vals[idx] is not None:
        l,r=2*idx+1,2*idx+2
        if l<n and vals[l] is not None: q.append((l,2*pos,lev+1))
        if r<n and vals[r] is not None: q.append((r,2*pos+1,lev+1))
print(mx)
