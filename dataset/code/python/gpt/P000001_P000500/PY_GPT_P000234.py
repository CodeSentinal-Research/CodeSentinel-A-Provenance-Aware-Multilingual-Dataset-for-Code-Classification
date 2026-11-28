# problem title : Boolean Matrix
# A zero in any row or column forces the entire row or column to zero.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; zr={i for i in range(r) if 0 in a[i]}; zc={j for j in range(c) if any(a[i][j]==0 for i in range(r))}
for i in range(r):
    print(*(0 if i in zr or j in zc else a[i][j] for j in range(c)))
