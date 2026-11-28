
a,b,c=int(input()),int(input()),int(input())
from math import gcd
g=gcd(a,b)
if c%g!=0: print('No solution');exit()
def ext_gcd(a,b):
    if b==0: return 1,0
    x,y=ext_gcd(b,a%b)
    return y,x-(a//b)*y
x0,y0=ext_gcd(a,b)
print(x0*(c//g),y0*(c//g))
