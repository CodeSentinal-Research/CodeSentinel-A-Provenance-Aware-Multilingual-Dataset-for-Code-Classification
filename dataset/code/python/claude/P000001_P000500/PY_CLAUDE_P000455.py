
n,d=map(int,input().split())
w=list(map(int,input().split()))
def ok(cap):
    days=1;curr=0
    for x in w:
        if curr+x>cap: days+=1;curr=x
        else: curr+=x
    return days<=d
lo,hi=max(w),sum(w)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
