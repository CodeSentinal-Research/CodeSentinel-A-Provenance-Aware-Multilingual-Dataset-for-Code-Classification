

n=int(input());bad=int(input())

lo,hi=1,n
while lo<hi:
    mid=(lo+hi)//2
    if mid>=bad: hi=mid
    else: lo=mid+1
print(lo)
