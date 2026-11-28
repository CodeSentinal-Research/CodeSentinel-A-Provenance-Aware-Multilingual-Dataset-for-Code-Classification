
from collections import deque
from sortedcontainers import SortedList
n=int(input());p=int(input());b=int(input());banned=set(map(int,input().split()));k=int(input())
dist=[-1]*n;dist[p]=0
sl=[SortedList(range(0,n,2)),SortedList(range(1,n,2))]
for bpos in banned: sl[bpos%2].discard(bpos)
sl[p%2].discard(p);q=deque([p])
while q:
    pos=q.popleft()
    lo=max(0,pos-k+1);hi=min(n-1,pos+k-1)
    mn=lo+hi-pos;mx=lo+hi-lo
    parity=mn%2
    lst=sl[parity]
    i=lst.bisect_left(mn)
    while i<len(lst) and lst[i]<=mx:
        nxt=lst[i];dist[nxt]=dist[pos]+1;q.append(nxt);lst.remove(nxt)
    parity2=mx%2
    if parity2!=parity:
        lst2=sl[parity2]
        i2=lst2.bisect_left(mn)
        while i2<len(lst2) and lst2[i2]<=mx:
            nxt=lst2[i2];dist[nxt]=dist[pos]+1;q.append(nxt);lst2.remove(nxt)
print(*dist)
