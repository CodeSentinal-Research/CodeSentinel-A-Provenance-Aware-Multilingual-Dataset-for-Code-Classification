
n = int(input())
A = [list(map(float, input().split())) for _ in range(n)]
def det(M):
    n=len(M); M=[r[:] for r in M]; d=1
    for i in range(n):
        pivot=i
        for k in range(i+1,n):
            if abs(M[k][i])>abs(M[pivot][i]): pivot=k
        M[i],M[pivot]=M[pivot],M[i]
        if M[i][i]==0: return 0
        if i!=pivot: d*=-1
        d*=M[i][i]
        for k in range(i+1,n):
            f=M[k][i]/M[i][i]
            for j in range(i,n): M[k][j]-=f*M[i][j]
    return d
res=det(A)
print(int(round(res)))
