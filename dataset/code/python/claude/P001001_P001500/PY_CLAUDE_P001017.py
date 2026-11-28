
import heapq
n=int(input());ropes=list(map(int,input().split()))
heapq.heapify(ropes);cost=0
while len(ropes)>1:
    a,b=heapq.heappop(ropes),heapq.heappop(ropes)
    cost+=a+b;heapq.heappush(ropes,a+b)
print(cost)
