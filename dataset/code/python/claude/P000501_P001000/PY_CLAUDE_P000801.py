
n,m=map(int,input().split());k=int(input())
grid=[list(map(int,input().split())) for _ in range(n)]
pre=[[0]*(m+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        pre[i][j]=grid[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]
res=[[0]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        r1,c1=max(0,i-k),max(0,j-k)
        r2,c2=min(n-1,i+k),min(m-1,j+k)
        res[i][j]=pre[r2+1][c2+1]-pre[r1][c2+1]-pre[r2+1][c1]+pre[r1][c1]
for row in res: print(*row)
