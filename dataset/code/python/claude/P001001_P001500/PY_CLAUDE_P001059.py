
import heapq
n=int(input());a=list(map(int,input().split()))

h=[]
for v in a:
    if v%2==1: v*=2
    heapq.heappush(h,-v)
best=max(a)-min(a)
while True:
    mx=-heapq.heappop(h)
    best=min(best,mx-(-h[0] if h else mx))
    if mx%2==1: break
    heapq.heappush(h,-(mx//2))
print(best)
