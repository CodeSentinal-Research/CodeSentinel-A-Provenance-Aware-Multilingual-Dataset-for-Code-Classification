# problem title : Count Zeros in a Sorted Matrix
# In a sorted binary-style matrix, count zeros row by row using binary search.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; z=0
for row in a:
    lo,hi=0,n
    while lo<hi:
        m=(lo+hi)//2
        if row[m]==0:hi=m
        else:lo=m+1
    z+=lo
print(z)
