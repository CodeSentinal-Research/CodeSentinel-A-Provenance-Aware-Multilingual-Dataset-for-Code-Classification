
from collections import deque
n=int(input());a=list(map(int,input().split()));k=int(input())
pre=[0]*(n+1)
for i in range(n): pre[i+1]=pre[i]+a[i]
ans=float('inf');dq=deque()
for i in range(n+1):
    while dq and pre[i]-pre[dq[0]]>=k: ans=min(ans,i-dq.popleft())
    while dq and pre[i]<=pre[dq[-1]]: dq.pop()
    dq.append(i)
print(-1 if ans==float('inf') else ans)
