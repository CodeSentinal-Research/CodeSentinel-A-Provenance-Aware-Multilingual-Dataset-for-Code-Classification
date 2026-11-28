
a,m=map(int,input().split());b,n=map(int,input().split())
from math import gcd
g=gcd(m,n)
if (b-a)%g!=0: print(-1);exit()
lcm=m*n//g
def ext_gcd(a,b):
    if b==0: return 1,0
    x,y=ext_gcd(b,a%b)
    return y,x-(a//b)*y
x,_=ext_gcd(m,n)
ans=(a+m*((b-a)//g)*x)%lcm
print(ans,lcm)
