
s=input().strip()
from collections import deque
visited={s};q=deque([s]);found=[]
while q:
    cur=q.popleft()
    if cur.count('(')==cur.count(')'): found.append(cur)
    if found: continue
    for i in range(len(cur)):
        if cur[i] not in '()': continue
        nxt=cur[:i]+cur[i+1:]
        if nxt not in visited: visited.add(nxt);q.append(nxt)
for r in sorted(set(found)): print(r)
