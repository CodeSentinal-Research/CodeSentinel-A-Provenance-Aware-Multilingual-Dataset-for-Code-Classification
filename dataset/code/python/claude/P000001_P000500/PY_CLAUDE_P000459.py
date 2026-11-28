
n=int(input())
a=list(map(int,input().split()))
lo,hi=0,n-1
while hi-lo>2:
    m1=lo+(hi-lo)//3
    m2=hi-(hi-lo)//3
    if a[m1]<a[m2]: lo=m1+1
    else: hi=m2-1
print(max(a[lo:hi+1]))
