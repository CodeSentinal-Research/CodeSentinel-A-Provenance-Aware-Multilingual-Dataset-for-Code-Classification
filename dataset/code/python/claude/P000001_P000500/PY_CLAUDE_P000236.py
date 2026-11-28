
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
suf_max = [[0]*n for _ in range(n)]
suf_max[n-1][n-1] = A[n-1][n-1]
for j in range(n-2,-1,-1): suf_max[n-1][j]=max(A[n-1][j],suf_max[n-1][j+1])
for i in range(n-2,-1,-1): suf_max[i][n-1]=max(A[i][n-1],suf_max[i+1][n-1])
for i in range(n-2,-1,-1):
    for j in range(n-2,-1,-1):
        suf_max[i][j]=max(A[i][j],suf_max[i+1][j],suf_max[i][j+1])
ans=float('-inf')
for i in range(n-1):
    for j in range(n-1):
        ans=max(ans, suf_max[i+1][j+1]-A[i][j])
print(ans)
