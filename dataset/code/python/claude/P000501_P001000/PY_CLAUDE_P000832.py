
n=int(input());a=list(map(int,input().split()));k=int(input())
def ok(mid):
    parts=cnt=0
    for v in a:
        if cnt+v>mid: parts+=1;cnt=0
        cnt+=v
    return parts+1<=k
lo,hi=max(a),sum(a)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
