
n=int(input());a=list(map(int,input().split()))
m=int(input());b=list(map(int,input().split()))
import heapq;res=list(heapq.merge(a,b));print(*res)
