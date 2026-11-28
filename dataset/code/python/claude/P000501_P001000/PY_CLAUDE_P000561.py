
from collections import Counter,deque
s=input().strip();cnt=Counter();q=deque();res=[]
for c in s:
    cnt[c]+=1;q.append(c)
    while q and cnt[q[0]]>1: q.popleft()
    res.append(q[0] if q else '#')
print(''.join(res))
