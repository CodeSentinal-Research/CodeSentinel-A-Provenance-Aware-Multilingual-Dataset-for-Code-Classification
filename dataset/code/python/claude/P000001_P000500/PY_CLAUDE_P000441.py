
n=int(input())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<hi:
    mid=(lo+hi+1)//2
    if a[mid]>=a[lo]: lo=mid
    else: hi=mid-1
print(a[lo])
