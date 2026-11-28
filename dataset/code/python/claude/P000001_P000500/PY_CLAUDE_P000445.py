
rows,cols,x=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(rows)]
lo,hi=0,rows*cols-1
while lo<=hi:
    mid=(lo+hi)//2
    v=mat[mid//cols][mid%cols]
    if v==x: print('Found');exit()
    elif v<x: lo=mid+1
    else: hi=mid-1
print('Not Found')
