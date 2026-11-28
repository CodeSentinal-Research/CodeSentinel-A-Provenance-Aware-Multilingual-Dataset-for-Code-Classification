
n,m=map(int,input().split());t=int(input())
grid=[list(map(int,input().split())) for _ in range(n)]
pre=[[0]*(m+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        pre[i][j]=grid[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]
best=0
for r1 in range(n):
    for c1 in range(m):
        for r2 in range(r1,n):
            for c2 in range(c1,m):
                if min(r2-r1,c2-c1)+1 > best:
                    s=pre[r2+1][c2+1]-pre[r1][c2+1]-pre[r2+1][c1]+pre[r1][c1]
                    if s<=t: best=min(r2-r1,c2-c1)+1
print(best)
