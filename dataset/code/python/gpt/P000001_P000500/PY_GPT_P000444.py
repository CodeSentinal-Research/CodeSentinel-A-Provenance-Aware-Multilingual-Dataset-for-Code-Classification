# problem title : Peak Index in Mountain Array
# In a mountain array, the slope changes from increasing to decreasing at the peak.
n=int(input());a=list(map(int,input().split()));l,r=0,n-1
while l<r:
 m=(l+r)//2
 if a[m]<a[m+1]:l=m+1
 else:r=m
print(l)
