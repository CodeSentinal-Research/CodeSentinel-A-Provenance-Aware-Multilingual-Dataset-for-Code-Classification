
import heapq
n,k=map(int,input().split());a=list(map(int,input().split()))

from collections import deque
h=[];res=[]
for i in range(n):
    heapq.heappush(h,(-a[i],i))
    while h[0][1]<=i-k: heapq.heappop(h)
    if i>=k-1: res.append(-h[0][0])
print(*res)
