
a,b,m=int(input()),int(input()),int(input())
from math import gcd
g=gcd(a,m)
if b%g!=0: print(-1);exit()
a,b,m=a//g,b//g,m//g
print(b*pow(a,m-2,m)%m if gcd(a,m)==1 else -1)
