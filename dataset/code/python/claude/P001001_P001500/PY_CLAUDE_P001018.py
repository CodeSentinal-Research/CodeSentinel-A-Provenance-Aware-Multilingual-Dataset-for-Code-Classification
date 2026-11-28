
import heapq
from collections import Counter
s=input().strip()
cnt=Counter(s);n=len(s)
if max(cnt.values())>(n+1)//2: print('');exit()
h=[(-v,c) for c,v in cnt.items()];heapq.heapify(h)
res=[];prev=None
while h:
    v,c=heapq.heappop(h)
    res.append(c)
    if prev and prev[0]<0: heapq.heappush(h,prev)
    prev=(v+1,c)
print(''.join(res))
