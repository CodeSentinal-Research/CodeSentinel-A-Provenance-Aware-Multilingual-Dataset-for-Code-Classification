# problem title : Check if Matrix is Orthogonal
# Orthogonality means A transpose times A equals the identity matrix.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; ok=True
for i in range(n):
    for j in range(n):
        if sum(a[k][i]*a[k][j] for k in range(n)) != (1 if i==j else 0): ok=False
print("Yes" if ok else "No")
