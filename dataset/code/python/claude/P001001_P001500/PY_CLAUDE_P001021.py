
import heapq
n=int(input());a=list(map(int,input().split()));i,v=map(int,input().split())
h=[-x for x in a];heapq.heapify(h)

a[i]=v
h=[-x for x in a];heapq.heapify(h)
print(*[-x for x in h])
