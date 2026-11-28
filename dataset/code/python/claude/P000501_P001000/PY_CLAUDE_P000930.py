
n,m,p=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(n)]
B=[list(map(int,input().split())) for _ in range(m)]
C=[[sum(A[i][k]*B[k][j] for k in range(m)) for j in range(p)] for i in range(n)]
for row in C: print(*row)
