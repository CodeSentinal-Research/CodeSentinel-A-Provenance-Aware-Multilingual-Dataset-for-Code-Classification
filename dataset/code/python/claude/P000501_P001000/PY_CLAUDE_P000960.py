
a,b,c=int(input()),int(input()),int(input())
from math import gcd
g=gcd(a,b)
if c%g!=0: print(-1);exit()
def ext_gcd(a,b):
    if b==0: return 1,0
    x,y=ext_gcd(b,a%b)
    return y,x-(a//b)*y
x,y=ext_gcd(a,b)
print(x*(c//g),y*(c//g))
