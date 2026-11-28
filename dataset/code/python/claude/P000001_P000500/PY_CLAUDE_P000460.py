
n,x=map(int,input().split())
a=list(map(int,input().split()))

lo,hi=0,n-1
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]<a[mid+1]: lo=mid+1
    else: hi=mid
peak=lo

lo2,hi2=0,peak
while lo2<=hi2:
    mid=(lo2+hi2)//2
    if a[mid]==x: print(mid);exit()
    elif a[mid]<x: lo2=mid+1
    else: hi2=mid-1

lo2,hi2=peak,n-1
while lo2<=hi2:
    mid=(lo2+hi2)//2
    if a[mid]==x: print(mid);exit()
    elif a[mid]>x: lo2=mid+1
    else: hi2=mid-1
print(-1)
