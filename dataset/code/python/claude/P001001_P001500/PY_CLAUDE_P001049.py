
import heapq
n,q=map(int,input().split());a=list(map(int,input().split()))
h=[-x for x in a];heapq.heapify(h)
for _ in range(q):
    i,v=map(int,input().split())
    a[i]=v
h=[-x for x in a];heapq.heapify(h)
print(*[-x for x in h])
