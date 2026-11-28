
n=int(input());w=list(map(int,input().split()));days=int(input())
def ok(cap):
    d,s=1,0
    for x in w:
        if x>cap: return False
        if s+x>cap: d+=1;s=0
        s+=x
    return d<=days
lo,hi=max(w),sum(w)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
