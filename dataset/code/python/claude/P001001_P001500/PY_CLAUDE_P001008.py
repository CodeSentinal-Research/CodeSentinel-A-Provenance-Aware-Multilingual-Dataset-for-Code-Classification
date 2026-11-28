
import heapq
n=int(input());a=list(map(int,input().split()));v=int(input())
heapq.heapify(a)
heapq.heappush(a,v)
print(*a)
