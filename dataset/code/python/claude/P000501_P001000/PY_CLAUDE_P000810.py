
n=int(input());a=list(map(int,input().split()));t=int(input())
lo,hi=0,n
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]<t: lo=mid+1
    else: hi=mid
print(lo)
