# problem title : Find Minimum in Rotated Sorted Array
# Binary search follows the side containing the rotation point.
n=int(input());a=list(map(int,input().split()));l,r=0,n-1
while l<r:
 m=(l+r)//2
 if a[m]>a[r]:l=m+1
 else:r=m
print(a[l])
