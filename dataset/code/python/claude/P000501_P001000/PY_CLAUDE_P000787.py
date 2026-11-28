
n=int(input());a=list(map(int,input().split()))

total=sum(a);lsum=0
for mid in range(n):
    rsum=total-lsum-a[mid]
    if lsum==rsum: print(mid);exit()
    lsum+=a[mid]
print(-1)
