
import heapq
k=int(input());lists=[]
for _ in range(k):
    sz=int(input());lists.append(list(map(int,input().split())))
merged=list(heapq.merge(*lists))
print(*merged)
