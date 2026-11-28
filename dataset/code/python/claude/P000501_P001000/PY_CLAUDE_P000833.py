
n=int(input());pages=list(map(int,input().split()));s=int(input())
def ok(mid):
    students=cnt=0
    for p in pages:
        if p>mid: return False
        if cnt+p>mid: students+=1;cnt=0
        cnt+=p
    return students+1<=s
lo,hi=max(pages),sum(pages)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
