# problem title : Find Saddle Point in Matrix
# A saddle point is the minimum in its row and maximum in its column.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; ans=None
for i,row in enumerate(a):
    v=min(row); j=row.index(v)
    if v==max(a[x][j] for x in range(n)): ans=v; break
print(ans if ans is not None else "No Saddle Point")
