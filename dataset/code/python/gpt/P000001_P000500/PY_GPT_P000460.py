# problem title : Search in Bitonic Array
# Find the peak, then binary-search the increasing and decreasing halves.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1
while l<r:
 m=(l+r)//2
 if a[m]<a[m+1]:l=m+1
 else:r=m
p=l
def bs(l,r,inc):
 while l<=r:
  m=(l+r)//2
  if a[m]==t:return m
  if inc:
   if a[m]<t:l=m+1
   else:r=m-1
  else:
   if a[m]>t:l=m+1
   else:r=m-1
 return -1
x=bs(0,p,True);print(x if x!=-1 else bs(p+1,n-1,False))
