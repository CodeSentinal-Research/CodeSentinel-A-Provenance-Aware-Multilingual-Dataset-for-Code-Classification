
n,m=map(int,input().split());mat=[list(map(int,input().split())) for _ in range(n)];t=int(input())
lo,hi=0,n*m-1
while lo<=hi:
    mid=(lo+hi)//2
    v=mat[mid//m][mid%m]
    if v==t: print('true');exit()
    elif v<t: lo=mid+1
    else: hi=mid-1
print('false')
