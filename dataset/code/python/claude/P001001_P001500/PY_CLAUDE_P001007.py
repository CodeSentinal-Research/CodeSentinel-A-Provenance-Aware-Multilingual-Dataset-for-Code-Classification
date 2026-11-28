
import heapq
n=int(input());a=list(map(int,input().split()));v=int(input())
h=[-x for x in a]
heapq.heappop(h)
heapq.heappush(h,-v)
print(*[-x for x in sorted(h,reverse=True)])
