
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    print(*[A[i][j] if j>=i else 0 for j in range(n)])
