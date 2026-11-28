
n=int(input());k=int(input())
A=[list(map(int,input().split())) for _ in range(n)]
MOD=10**9+7
def mat_mul(X,Y):
    r=len(X);s=len(Y[0]);m=len(Y)
    return [[sum(X[i][t]*Y[t][j] for t in range(m))%MOD for j in range(s)] for i in range(r)]
def mat_pow(M,p):
    res=[[1 if i==j else 0 for j in range(n)] for i in range(n)]
    while p:
        if p&1: res=mat_mul(res,M)
        M=mat_mul(M,M);p>>=1
    return res
R=mat_pow(A,k)
for row in R: print(*row)
