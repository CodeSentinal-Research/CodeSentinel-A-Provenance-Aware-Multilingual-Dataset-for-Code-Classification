
n=int(input())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<hi:
    mid=(lo+hi)//2
    if mid%2==1: mid-=1
    if a[mid]==a[mid+1]: lo=mid+2
    else: hi=mid
print(a[lo])
