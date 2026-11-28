
a,b,c=int(input()),int(input()),int(input())
xl,xr=map(int,input().split());yl,yr=map(int,input().split())
from math import gcd
g=gcd(a,b)
if c%g!=0: print(0);exit()
cnt=0
for x in range(xl,xr+1):
    rem=c-a*x
    if rem%b==0 and yl<=rem//b<=yr: cnt+=1
print(cnt)
