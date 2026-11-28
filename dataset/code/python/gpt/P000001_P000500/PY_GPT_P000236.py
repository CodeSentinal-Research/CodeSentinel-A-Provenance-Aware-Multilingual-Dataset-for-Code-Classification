# problem title : Find Specific Pair in Matrix
# Scan cells from bottom-right while maintaining the largest value below-right.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; mx=a[-1][-1]; ans=-10**18
for i in range(n-2,-1,-1):
    for j in range(n-2,-1,-1): ans=max(ans,mx-a[i][j]); mx=max(mx,a[i][j])
print(ans)
