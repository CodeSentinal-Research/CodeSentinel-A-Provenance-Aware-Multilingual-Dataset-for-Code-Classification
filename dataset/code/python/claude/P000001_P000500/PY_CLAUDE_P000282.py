
s1,s2=input().split();m,n=len(s1),len(s2)
dp=[[0]*(n+1) for _ in range(m+1)];best=0;end=0
for i in range(1,m+1):
    for j in range(1,n+1):
        if s1[i-1]==s2[j-1]:
            dp[i][j]=dp[i-1][j-1]+1
            if dp[i][j]>best: best=dp[i][j];end=i
print(s1[end-best:end])
