
n=int(input());boards=list(map(int,input().split()));p=int(input())
def ok(mid):
    painters=time=0
    for b in boards:
        if b>mid: return False
        if time+b>mid: painters+=1;time=0
        time+=b
    return painters+1<=p
lo,hi=max(boards),sum(boards)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
