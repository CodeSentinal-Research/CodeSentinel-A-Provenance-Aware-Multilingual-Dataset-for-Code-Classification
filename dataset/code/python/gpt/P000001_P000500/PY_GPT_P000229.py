# problem title : Find Row with Maximum 1s
# For each sorted binary row, binary search the first 1 and compare its count.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; best=-1; mx=-1
for i,row in enumerate(a):
    lo,hi=0,c
    while lo<hi:
        m=(lo+hi)//2
        if row[m]:hi=m
        else:lo=m+1
    if c-lo>mx:mx=c-lo;best=i
print(best)
