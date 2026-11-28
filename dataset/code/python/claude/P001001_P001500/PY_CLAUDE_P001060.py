
import heapq
n,k=map(int,input().split());a=list(map(int,input().split()))
window=a[:k+1];heapq.heapify(window)
res=[]
for i in range(n):
    res.append(heapq.heappop(window))
    if i+k+1<n: heapq.heappush(window,a[i+k+1])
print(*res)
