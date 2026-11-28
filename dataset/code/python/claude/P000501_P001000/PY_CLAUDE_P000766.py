
expr=input().strip()
operands=[c for c in expr if c in 'TF']
operators=[c for c in expr if c in '&|^']
n=len(operands);MOD=10**9+7
T=[[0]*n for _ in range(n)];F=[[0]*n for _ in range(n)]
for i in range(n): T[i][i]=1 if operands[i]=='T' else 0;F[i][i]=0 if operands[i]=='T' else 1
for ln in range(2,n+1):
    for i in range(n-ln+1):
        j=i+ln-1
        for k in range(i,j):
            op=operators[k]
            lt,lf,rt,rf=T[i][k],F[i][k],T[k+1][j],F[k+1][j]
            if op=='&': T[i][j]+=lt*rt
            elif op=='|': T[i][j]+=lt*rt+lt*rf+lf*rt
            elif op=='^': T[i][j]+=lt*rf+lf*rt
            T[i][j]%=MOD
print(T[0][n-1])
