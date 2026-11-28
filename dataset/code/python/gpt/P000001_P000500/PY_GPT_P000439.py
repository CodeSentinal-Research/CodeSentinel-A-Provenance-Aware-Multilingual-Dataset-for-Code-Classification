# problem title : Search in Rotated Sorted Array
# One half of a rotated sorted array is always normally ordered.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1
while l<=r:
 m=(l+r)//2
 if a[m]==t:print(m);break
 if a[l]<=a[m]:
  if a[l]<=t<a[m]:r=m-1
  else:l=m+1
 else:
  if a[m]<t<=a[r]:l=m+1
  else:r=m-1
else:print(-1)
