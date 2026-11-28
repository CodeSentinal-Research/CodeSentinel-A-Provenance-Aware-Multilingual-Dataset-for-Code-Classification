
import heapq
n=int(input());a=list(map(int,input().split()));i,v=map(int,input().split())
a[i]=v
heapq.heapify(a)
print(*a)
