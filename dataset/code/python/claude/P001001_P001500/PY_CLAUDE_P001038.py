
import heapq
n,k=map(int,input().split());profits=list(map(int,input().split()));capitals=list(map(int,input().split()))
w=int(input())
projects=sorted(zip(capitals,profits))
h=[];i=0
for _ in range(k):
    while i<n and projects[i][0]<=w:
        heapq.heappush(h,-projects[i][1]);i+=1
    if not h: break
    w+=-heapq.heappop(h)
print(w)
