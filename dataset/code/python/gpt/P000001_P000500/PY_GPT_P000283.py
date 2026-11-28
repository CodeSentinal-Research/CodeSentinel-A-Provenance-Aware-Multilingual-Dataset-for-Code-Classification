# problem title : Longest Common Subsequence Length
# LCS dynamic programming compares prefixes and keeps the best subsequence length.
a=input(); b=input(); dp=[0]*(len(b)+1)
for x in a:
    old=0
    for j,y in enumerate(b,1):
        temp=dp[j]
        dp[j]=old+1 if x==y else max(dp[j],dp[j-1])
        old=temp
print(dp[-1])
