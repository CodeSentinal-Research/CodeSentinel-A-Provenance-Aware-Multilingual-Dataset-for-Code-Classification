
from collections import deque
n=int(input());a=list(map(int,input().split()));k=int(input())
dp=a[:];dq=deque()
for i in range(n):
    while dq and dq[0]<i-k: dq.popleft()
    if dq: dp[i]=max(dp[i],dp[dq[0]]+a[i])
    while dq and dp[dq[-1]]<=dp[i]: dq.pop()
    if dp[i]>0: dq.append(i)
print(max(dp))
