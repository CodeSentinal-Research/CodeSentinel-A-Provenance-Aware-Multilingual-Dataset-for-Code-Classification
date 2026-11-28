
n=int(input());m=int(input());batt=list(map(int,input().split()))
def ok(t):
    return sum(min(b,t) for b in batt)>=n*t
lo,hi=0,sum(batt)//n
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
