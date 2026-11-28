
import heapq
k=int(input())
lists=[list(map(int,input().split())) for _ in range(k)]
h=[]
for i,lst in enumerate(lists):
    if lst: heapq.heappush(h,(lst[0],i,0))
mx=max(lst[0] for lst in lists if lst)
best=float('inf');best_range=None
while h:
    mn,i,j=h[0]
    if mx-mn<best: best=mx-mn;best_range=[mn,mx]
    nxt_i,nxt_j=h[0][1],h[0][2]+1
    if nxt_j>=len(lists[nxt_i]): break
    heapq.heappop(h)
    nv=lists[nxt_i][nxt_j]
    heapq.heappush(h,(nv,nxt_i,nxt_j))
    mx=max(mx,nv)
print(*best_range)
