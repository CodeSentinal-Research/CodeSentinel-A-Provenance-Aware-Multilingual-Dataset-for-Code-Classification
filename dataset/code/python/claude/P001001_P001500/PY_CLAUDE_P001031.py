
import heapq
n,m=map(int,input().split());a=list(map(int,input().split()));b=list(map(int,input().split()))
merged=a+b;heapq.heapify(merged)
print(*[-x for x in sorted([-x for x in merged])])
