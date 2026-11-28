
n=int(input());cards=sorted(map(int,input().split()))
from collections import deque
idx=deque(range(n));ans=[0]*n
for c in cards:
    ans[idx.popleft()]=c
    if idx: idx.append(idx.popleft())
print(*ans)

