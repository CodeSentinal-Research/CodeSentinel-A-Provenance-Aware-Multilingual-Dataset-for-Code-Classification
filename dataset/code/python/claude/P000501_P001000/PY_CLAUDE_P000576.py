
from collections import deque,defaultdict
n=int(input());vals=list(map(lambda x: None if x=='null' else int(x),input().split()))
if not vals or vals[0] is None: exit()
cols=defaultdict(list);q=deque([(0,0,0)])
while q:
    idx,col,row=q.popleft()
    if idx>=n or vals[idx] is None: continue
    cols[col].append((row,vals[idx]))
    q.append((2*idx+1,col-1,row+1));q.append((2*idx+2,col+1,row+1))
for col in sorted(cols):
    print(*[str(v) for _,v in sorted(cols[col])])
