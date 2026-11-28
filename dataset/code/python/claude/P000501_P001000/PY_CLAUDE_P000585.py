
n=int(input());a=list(map(int,input().split()))
res=[];lo,hi=0,n-1
while lo<=hi:
    if lo==hi: res.append(a[lo]);break
    res.append(a[lo]);res.append(a[hi]);lo+=1;hi-=1
print(*res)
