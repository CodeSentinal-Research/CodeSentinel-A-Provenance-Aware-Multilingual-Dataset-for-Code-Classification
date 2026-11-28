# problem title : Search Insert Position
# Lower bound is exactly the insertion position preserving sorted order.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n
while l<r:
 m=(l+r)//2
 if a[m]<t:l=m+1
 else:r=m
print(l)
