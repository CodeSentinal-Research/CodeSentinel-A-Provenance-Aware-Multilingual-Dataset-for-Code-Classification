
n,k=map(int,input().split())
a=list(map(int,input().split()))
lo,hi=0,n
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]-(mid+1)>=k: hi=mid
    else: lo=mid+1
print(lo+k)
