
import heapq
n=int(input());a=list(map(int,input().split()))
h=[-x for x in a]
heapq.heapify(h)
print(-heapq.heappop(h))
