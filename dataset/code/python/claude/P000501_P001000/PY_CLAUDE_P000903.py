
n=int(input());a=sorted(map(int,input().split()))
dp=[1]*n;prev=[-1]*n
for i in range(n):
    for j in range(i):
        if a[i]%a[j]==0 and dp[j]+1>dp[i]:
            dp[i]=dp[j]+1;prev[i]=j
best=max(range(n),key=lambda i:dp[i])
res=[]
while best!=-1: res.append(a[best]);best=prev[best]
print(*reversed(res))
