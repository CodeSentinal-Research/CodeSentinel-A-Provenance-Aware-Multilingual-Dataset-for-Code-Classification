
a,b=int(input()),int(input())
from math import gcd
g=gcd(a,b)
def ext_gcd(a,b):
    if b==0: return 1,0
    x,y=ext_gcd(b,a%b)
    return y,x-(a//b)*y
x,y=ext_gcd(a,b)
x*=g;y*=g
step_x=b//g;step_y=a//g
if x<=0: k=(-x+step_x-1)//step_x;x+=k*step_x;y-=k*step_y
print(x,y)
