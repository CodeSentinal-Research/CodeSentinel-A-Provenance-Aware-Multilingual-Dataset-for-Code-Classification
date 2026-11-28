
import heapq
from collections import Counter
n=int(input());tasks=input().split();n_val,k=int(input()),int(input())
cnt=Counter(tasks)
h=[(-v,c) for c,v in cnt.items()];heapq.heapify(h)
time=0
while h:
    tmp=[];i=0
    while i<=k and h:
        v,c=heapq.heappop(h)
        tmp.append((v+1,c));time+=1;i+=1
    time+=max(0,k+1-i)
    for v,c in tmp:
        if v<0: heapq.heappush(h,(v,c))
print(time)
