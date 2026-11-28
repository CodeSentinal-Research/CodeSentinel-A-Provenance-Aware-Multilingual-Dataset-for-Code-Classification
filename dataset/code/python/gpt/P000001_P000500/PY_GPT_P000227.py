# problem title : Maximum Sum Rectangle in 2D Matrix
# Compress pairs of columns into a 1D array and apply Kadane's algorithm.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; best=-10**18
for l in range(c):
    col=[0]*r
    for rr in range(l,c):
        for i in range(r): col[i]+=a[i][rr]
        cur=col[0]
        for v in col[1:]: cur=max(v,cur+v)
        best=max(best,cur)
print(best)
