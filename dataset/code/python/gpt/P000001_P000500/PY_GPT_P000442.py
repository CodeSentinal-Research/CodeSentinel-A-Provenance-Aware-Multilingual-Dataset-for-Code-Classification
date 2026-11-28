# problem title : Search in Rotated Sorted Array with Duplicates
# With duplicates, equal endpoints may hide which half is sorted, so shrink both ends.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1;ans=-1
while l<=r:
 m=(l+r)//2
 if a[m]==t:ans=m;break
 if a[l]==a[m]==a[r]:l+=1;r-=1;continue
 if a[l]<=a[m]:
  if a[l]<=t<a[m]:r=m-1
  else:l=m+1
 else:
  if a[m]<t<=a[r]:l=m+1
  else:r=m-1
print(ans)
