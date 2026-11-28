# problem title : Sum of Boundary Elements
# Sum the outer ring without adding any corner twice.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; s=0
for i in range(r):
    for j in range(c):
        if i in (0,r-1) or j in (0,c-1): s+=a[i][j]
print(s)
