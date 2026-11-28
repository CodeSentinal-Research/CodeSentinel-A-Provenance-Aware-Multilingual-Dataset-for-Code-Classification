# problem title : Find First and Last Position
# Lower and upper bounds locate the first and last target positions.
n,t=map(int,input().split());a=list(map(int,input().split()))
def lb():
 l,r=0,n
 while l<r:
  m=(l+r)//2
  if a[m]<t:l=m+1
  else:r=m
 return l
lo=lb()
if lo==n or a[lo]!=t:print(-1,-1)
else:
 l,r=lo,n
 while l<r:
  m=(l+r)//2
  if a[m]<=t:l=m+1
  else:r=m
 print(lo,l-1)
