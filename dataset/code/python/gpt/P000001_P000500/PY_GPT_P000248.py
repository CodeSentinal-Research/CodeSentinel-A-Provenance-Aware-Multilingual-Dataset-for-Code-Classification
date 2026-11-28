# problem title : Add Two Matrices
# Add corresponding entries from the two matrices.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; b=[list(map(int,input().split())) for _ in range(r)]
for i in range(r): print(*(a[i][j]+b[i][j] for j in range(c)))
