
s=input().strip()
from collections import deque
visited=set([s]);q=deque([s]);res=[];found=False
while q:
    cur=q.popleft()

    cnt=0;valid=True
    for c in cur:
        if c=='(': cnt+=1
        elif c==')':
            cnt-=1
            if cnt<0: valid=False;break
    if valid and cnt==0:
        res.append(cur);found=True
    if found: continue
    for i in range(len(cur)):
        if cur[i] not in '()': continue
        nxt=cur[:i]+cur[i+1:]
        if nxt not in visited: visited.add(nxt);q.append(nxt)
print('\n'.join(res) if res else '""')
