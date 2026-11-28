
import heapq
k=int(input());lists=[list(map(int,input().split())) for _ in range(k)]
h=[];res=[]
for i,lst in enumerate(lists):
    if lst: heapq.heappush(h,(lst[0],i,0))
while h:
    v,i,j=heapq.heappop(h);res.append(v)
    if j+1<len(lists[i]): heapq.heappush(h,(lists[i][j+1],i,j+1))
print(*res)
