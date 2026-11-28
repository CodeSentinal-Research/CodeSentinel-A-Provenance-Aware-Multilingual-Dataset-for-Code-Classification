# problem title : Word Break
# DP marks whether each prefix can be formed from dictionary words.
s=input(); words=set(input().split()); n=len(s); dp=[False]*(n+1); dp[0]=True
for i in range(1,n+1): dp[i]=any(dp[j] and s[j:i] in words for j in range(i))
print("Yes" if dp[n] else "No")
