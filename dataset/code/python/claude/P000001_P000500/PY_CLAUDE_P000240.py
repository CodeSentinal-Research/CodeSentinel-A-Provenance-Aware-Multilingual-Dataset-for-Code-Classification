
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
s = sum(A[0])+sum(A[r-1])
for i in range(1,r-1): s+=A[i][0]+A[i][c-1]
print(s)
