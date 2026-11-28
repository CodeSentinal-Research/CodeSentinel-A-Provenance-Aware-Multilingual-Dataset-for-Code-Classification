# problem title : Boundary Elements of Matrix
# Add each boundary position once, avoiding double-counting corners.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; out=[]
for j in range(c): out.append(a[0][j])
for i in range(1,r): out.append(a[i][c-1])
if r>1:
    for j in range(c-2,-1,-1): out.append(a[r-1][j])
if c>1:
    for i in range(r-2,0,-1): out.append(a[i][0])
print(*out)
