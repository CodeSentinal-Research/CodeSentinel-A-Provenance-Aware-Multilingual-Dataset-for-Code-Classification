
n=int(input())
a=list(map(int,input().split()))
lo,hi=1,n-2
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]<a[mid+1]: lo=mid+1
    else: hi=mid
print(lo)
