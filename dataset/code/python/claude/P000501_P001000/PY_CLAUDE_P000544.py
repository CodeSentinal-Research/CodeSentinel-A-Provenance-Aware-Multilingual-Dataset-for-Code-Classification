
from collections import deque
d=int(input());dead=set(input().split() for _ in range(d))
target=input().strip()
start='0000'
if start in dead: print(-1);exit()
if start==target: print(0);exit()
q=deque([(start,0)]);visited={start}
while q:
    node,steps=q.popleft()
    for i in range(4):
        for d2 in [1,-1]:
            nxt=list(node)
            nxt[i]=str((int(nxt[i])+d2)%10)
            nxt=''.join(nxt)
            if nxt==target: print(steps+1);exit()
            if nxt not in visited and nxt not in dead: visited.add(nxt);q.append((nxt,steps+1))
print(-1)
