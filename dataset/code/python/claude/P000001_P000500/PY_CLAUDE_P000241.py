
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    mn = min(A[i]); j = A[i].index(mn)
    if all(A[k][j]>=mn for k in range(n)): print(i, j, mn); exit()
print('No Saddle Point')
