# problem title : Search in Nearly Sorted Array
# In a nearly sorted array, a target can only be near the normal binary-search midpoint.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1
while l<=r:
 m=(l+r)//2
 if a[m]==t:print(m);break
 if m>l and a[m-1]==t:print(m-1);break
 if m<r and a[m+1]==t:print(m+1);break
 if a[m]>t:r=m-2
 else:l=m+2
else:print(-1)
