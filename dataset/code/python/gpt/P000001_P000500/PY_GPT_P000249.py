# problem title : Multiply Two Matrices
# Standard matrix multiplication combines row i of A with column j of B.
r1,c1=map(int,input().split()); r2,c2=map(int,input().split()); A=[list(map(int,input().split())) for _ in range(r1)]; B=[list(map(int,input().split())) for _ in range(r2)]
for i in range(r1): print(*(sum(A[i][k]*B[k][j] for k in range(c1)) for j in range(c2)))
