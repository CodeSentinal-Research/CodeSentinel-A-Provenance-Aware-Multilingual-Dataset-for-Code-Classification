
n=int(input())
from math import gcd
def ext_gcd(a,b):
    if b==0: return a,1,0
    g,x,y=ext_gcd(b,a%b)
    return g,y,x-(a//b)*y
ans=0;m=1
for _ in range(n):
    r,mod=map(int,input().split())
    g,x,_=ext_gcd(m,mod)
    if (r-ans)%g!=0: print(-1);exit()
    lcm=m*mod//g;ans=(ans+m*((r-ans)//g)*x)%lcm;m=lcm
print(ans%m)
