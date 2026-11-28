# problem title : Find Floor in Sorted Array
# Upper bound minus one gives the greatest array value not exceeding the target.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1;ans=-1
while l<=r:
 m=(l+r)//2
 if a[m]<=t:ans=a[m];l=m+1
 else:r=m-1
print(ans)
