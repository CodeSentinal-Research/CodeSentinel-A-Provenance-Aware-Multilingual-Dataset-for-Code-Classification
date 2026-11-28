
import heapq
n,k=map(int,input().split())
points=[tuple(map(int,input().split())) for _ in range(n)]
print(*heapq.nsmallest(k,points,key=lambda p:p[0]**2+p[1]**2))
