
import heapq
n=int(input());a=list(map(int,input().split()))
heapq.heapify(a)
for _ in range(n): print(heapq.heappop(a),end=' ')
print()
