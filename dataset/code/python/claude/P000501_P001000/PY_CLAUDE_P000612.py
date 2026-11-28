
from math import gcd
n=int(input());a=list(map(int,input().split()))
res=[]
for i in range(n-1): res.append(a[i]);res.append(gcd(a[i],a[i+1]))
res.append(a[-1])
print(*res)
