
import heapq
n,k=map(int,input().split());speeds=list(map(int,input().split()));efficiencies=list(map(int,input().split()))
MOD=10**9+7
workers=sorted(zip(efficiencies,speeds),reverse=True)
h=[];speed_sum=0;best=0
for eff,spd in workers:
    heapq.heappush(h,spd);speed_sum+=spd
    if len(h)>k: speed_sum-=heapq.heappop(h)
    best=max(best,speed_sum*eff)
print(best%MOD)
