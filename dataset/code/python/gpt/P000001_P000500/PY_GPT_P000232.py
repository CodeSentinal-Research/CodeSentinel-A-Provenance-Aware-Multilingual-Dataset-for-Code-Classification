# problem title : Find Median in Row-wise Sorted Matrix
# Binary-search the value whose rank is just above half of the matrix.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; lo=min(row[0] for row in a); hi=max(row[-1] for row in a); need=(r*c+1)//2
while lo<hi:
    m=(lo+hi)//2; count=sum(__import__('bisect').bisect_right(row,m) for row in a)
    if count<need:lo=m+1
    else:hi=m
print(lo)
