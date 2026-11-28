
s=input();n=len(s);dp=[0]*n
best=0
for i in range(1,n):
    if s[i]==')':
        if s[i-1]=='(': dp[i]=((dp[i-2]) if i>=2 else 0)+2
        elif dp[i-1]>0:
            j=i-dp[i-1]-1
            if j>=0 and s[j]=='(': dp[i]=dp[i-1]+2+(dp[j-1] if j>0 else 0)
        best=max(best,dp[i])
print(best)
