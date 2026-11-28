
n,m=map(int,input().split())
a=list(map(int,input().split()))
def ok(cap):
    parts=1;curr=0
    for x in a:
        if curr+x>cap: parts+=1;curr=x
        else: curr+=x
    return parts<=m
lo,hi=max(a),sum(a)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
