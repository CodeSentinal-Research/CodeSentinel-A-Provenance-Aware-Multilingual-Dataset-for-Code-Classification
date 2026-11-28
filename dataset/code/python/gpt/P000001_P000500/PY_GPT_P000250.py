# problem title : Find Determinant of a Matrix
# Gaussian elimination converts the matrix to triangular form while tracking row swaps.
n=int(input()); a=[list(map(float,input().split())) for _ in range(n)]; det=1
for i in range(n):
    p=max(range(i,n),key=lambda x:abs(a[x][i]))
    if abs(a[p][i])<1e-12: det=0; break
    if p!=i: a[i],a[p]=a[p],a[i]; det=-det
    pivot=a[i][i]; det*=pivot
    for r in range(i+1,n):
        f=a[r][i]/pivot
        for j in range(i+1,n): a[r][j]-=f*a[i][j]
print(int(round(det)))
