
n=int(input());a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]>a[hi]: lo=mid+1
    else: hi=mid
print(a[lo])
