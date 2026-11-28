# problem title : Find Fixed Point
# Binary search compares a[i] with i in a sorted distinct array.
n=int(input());a=list(map(int,input().split()));l,r=0,n-1;ans=-1
while l<=r:
 m=(l+r)//2
 if a[m]==m:ans=m;break
 if a[m]<m:l=m+1
 else:r=m-1
print(ans)
