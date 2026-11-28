# problem title : Find Ceiling in Sorted Array
# Lower bound locates the smallest value that is at least the target.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1;ans=-1
while l<=r:
 m=(l+r)//2
 if a[m]>=t:ans=a[m];r=m-1
 else:l=m+1
print(ans)
