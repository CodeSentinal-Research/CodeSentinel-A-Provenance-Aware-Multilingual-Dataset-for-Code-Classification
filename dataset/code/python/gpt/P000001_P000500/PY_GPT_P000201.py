# problem title : Maximum Sum Increasing Subsequence
# Dynamic programming tracks the best increasing subsequence sum ending at each index.
import sys
n=int(input()); a=list(map(int,input().split()))
dp=a[:]
for i in range(n):
    for j in range(i):
        if a[j]<a[i]: dp[i]=max(dp[i],dp[j]+a[i])
print(max(dp))
