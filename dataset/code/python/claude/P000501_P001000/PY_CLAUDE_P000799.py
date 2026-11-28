
n,m=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(n)]
pre=[[0]*(m+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        pre[i][j]=grid[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]
for row in pre[1:]: print(*row[1:])
