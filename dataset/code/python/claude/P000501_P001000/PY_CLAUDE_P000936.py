
n=int(input());A=[list(map(int,input().split())) for _ in range(n)]
print('true' if all(A[i][j]==A[j][i] for i in range(n) for j in range(n)) else 'false')
