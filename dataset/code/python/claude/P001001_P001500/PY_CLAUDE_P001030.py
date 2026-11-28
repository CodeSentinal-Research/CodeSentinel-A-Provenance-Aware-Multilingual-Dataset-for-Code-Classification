
import heapq
n=int(input());a=list(map(int,input().split()))

heapq.heapify(a)
result=list(a)
print(*result)
