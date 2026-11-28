
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==x: print(mid);exit()
    if mid>lo and a[mid-1]==x: print(mid-1);exit()
    if mid<hi and a[mid+1]==x: print(mid+1);exit()
    if a[mid]<x: lo=mid+2
    else: hi=mid-2
print(-1)
