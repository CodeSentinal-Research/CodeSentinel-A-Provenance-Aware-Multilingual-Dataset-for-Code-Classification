
n=int(input());a=list(map(int,input().split()));p=int(input())
a.sort()
def ok(mid):
    cnt=0
    for i in range(n-1,0,-1):
        if a[i]-a[i-1]>mid:
            cnt+=1
            if cnt>=p: return True
    return cnt>=p
lo,hi=0,a[-1]-a[0]
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
