
import heapq
k=int(input());lists=[]
for _ in range(k):
    sz=int(input());lists.append(list(map(int,input().split())))
print(*list(heapq.merge(*lists)))
