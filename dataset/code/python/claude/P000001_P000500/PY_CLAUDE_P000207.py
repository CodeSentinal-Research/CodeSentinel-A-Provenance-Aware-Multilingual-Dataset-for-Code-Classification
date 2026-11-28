
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
best = float('-inf')
for i in range(r - 2):
    for j in range(c - 2):
        s = A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2]
        best = max(best, s)
print(best)
