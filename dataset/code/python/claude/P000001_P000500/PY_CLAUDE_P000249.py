
r1, c1, c2 = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r1)]
B = [list(map(int, input().split())) for _ in range(c1)]
for i in range(r1):
    print(*[sum(A[i][k]*B[k][j] for k in range(c1)) for j in range(c2)])
