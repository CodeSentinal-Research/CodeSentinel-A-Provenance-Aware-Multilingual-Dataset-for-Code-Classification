
import heapq
n,k=map(int,input().split());a=list(map(int,input().split()));b=list(map(int,input().split()))
pairs=sorted((a[i]+b[j],i,j) for i in range(min(k,n)) for j in range(min(k,n)))
print(*[p[0] for p in pairs[:k]])
