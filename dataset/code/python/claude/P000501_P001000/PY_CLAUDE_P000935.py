
n=int(input());A=[list(map(int,input().split())) for _ in range(n)]
print(sum(A[i][i] for i in range(n)),sum(A[i][n-1-i] for i in range(n)))
