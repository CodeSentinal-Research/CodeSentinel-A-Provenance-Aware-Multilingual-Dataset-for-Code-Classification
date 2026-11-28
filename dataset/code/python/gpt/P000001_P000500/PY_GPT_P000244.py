# problem title : Maximum Sum Path in Matrix
# Dynamic programming keeps the best path sum reaching every cell from top or left.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; dp=[[0]*c for _ in range(r)]
for i in range(r):
    for j in range(c):
        dp[i][j]=a[i][j]+(max(dp[i-1][j] if i else -10**18,dp[i][j-1] if j else -10**18) if i or j else 0)
print(dp[-1][-1])
