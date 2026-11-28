
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
res=[]
for j in range(c): res.append(A[0][j])
for i in range(1,r-1): res.append(A[i][0]); res.append(A[i][c-1])
if r>1:
    for j in range(c): res.append(A[r-1][j])
print(*res)
