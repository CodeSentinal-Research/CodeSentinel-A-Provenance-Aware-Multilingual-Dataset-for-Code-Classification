# problem title : Find Maximum in Rotated Sorted Array
# The maximum is the element just before the minimum in a rotated sorted array.
n=int(input());a=list(map(int,input().split()));l,r=0,n-1
while l<r:
 m=(l+r)//2
 if a[m]>a[r]:l=m+1
 else:r=m
idx=(l-1)%n;print(a[idx])
