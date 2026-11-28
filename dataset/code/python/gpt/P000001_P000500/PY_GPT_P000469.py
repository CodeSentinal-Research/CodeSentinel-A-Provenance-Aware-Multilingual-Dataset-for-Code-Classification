# problem title : Search for a Range
# Find the first and last occurrence with two boundary searches.
n,t=map(int,input().split());a=list(map(int,input().split()));
lo=0;hi=n
while lo<hi:
 m=(lo+hi)//2
 if a[m]<t:lo=m+1
 else:hi=m
if lo==n or a[lo]!=t:print(-1,-1)
else:
 l,r=lo,n
 while l<r:
  m=(l+r)//2
  if a[m]<=t:l=m+1
  else:r=m
 print(lo,l-1)
