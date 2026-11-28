
import heapq
n,k=map(int,input().split());a=list(map(int,input().split()))
print(*heapq.nlargest(k,a))
