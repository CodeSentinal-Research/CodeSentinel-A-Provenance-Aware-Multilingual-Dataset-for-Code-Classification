# problem title : Maximum Sum of Hourglass in Matrix
# Each hourglass uses seven cells: three top, one middle, and three bottom.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]
best=-10**18
for i in range(r-2):
    for j in range(c-2):
        v=sum(a[i][j:j+3])+a[i+1][j+1]+sum(a[i+2][j:j+3]); best=max(best,v)
print(best)
