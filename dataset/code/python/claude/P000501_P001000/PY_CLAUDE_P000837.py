
n=int(input());stations=list(map(int,input().split()));k=int(input())
def ok(d):
    added=0
    for i in range(1,n):
        added+=int((stations[i]-stations[i-1])/d)-1 if d>0 else 0
        import math
        added=sum(math.ceil((stations[i]-stations[i-1])/d)-1 for i in range(1,n))
        return added<=k
    return True
lo,hi=0.0,stations[-1]-stations[0]
for _ in range(100):
    mid=(lo+hi)/2
    import math
    cnt=sum(math.ceil((stations[i]-stations[i-1])/mid)-1 for i in range(1,n)) if mid>0 else float('inf')
    if cnt<=k: hi=mid
    else: lo=mid
print(f'{hi:.6f}')
