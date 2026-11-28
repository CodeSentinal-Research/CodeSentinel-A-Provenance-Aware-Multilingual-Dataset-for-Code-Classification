
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<hi:
    if abs(a[lo]-x)<=abs(a[hi]-x): hi-=1
    else: lo+=1
print(a[lo])
