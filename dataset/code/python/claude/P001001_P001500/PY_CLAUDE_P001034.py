
import heapq
k=int(input())
class Node:
    def __init__(self,v,nx=None): self.v=v;self.nx=nx
    def __lt__(self,o): return self.v<o.v
res=[]
h=[]
for _ in range(k):
    sz=int(input());vals=list(map(int,input().split()))
    if vals:
        head=None
        for v in reversed(vals): head=Node(v,head)
        heapq.heappush(h,head)
while h:
    node=heapq.heappop(h);res.append(node.v)
    if node.nx: heapq.heappush(h,node.nx)
print(*res)
