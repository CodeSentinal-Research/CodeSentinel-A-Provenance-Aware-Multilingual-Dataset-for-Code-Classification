
import heapq
n,k=map(int,input().split());wages=list(map(int,input().split()));qualities=list(map(int,input().split()))
workers=sorted((w/q,q,w) for w,q in zip(wages,qualities))
h=[];q_sum=0;best=float('inf')
for ratio,q,_ in workers:
    heapq.heappush(h,-q);q_sum+=q
    if len(h)>k: q_sum+=heapq.heappop(h)
    if len(h)==k: best=min(best,ratio*q_sum)
print(best)
