
n,m=map(int,input().split())
a=list(map(int,input().split()))
def feasible(mid):
    students=1;curr=0
    for p in a:
        if p>mid: return False
        if curr+p>mid: students+=1;curr=p
        else: curr+=p
    return students<=m
lo,hi,ans=max(a),sum(a),sum(a)
while lo<=hi:
    mid=(lo+hi)//2
    if feasible(mid): ans=mid;hi=mid-1
    else: lo=mid+1
print(ans)
