# problem title : Search in Infinite Sorted Array
# The supplied array is finite in input, so ordinary binary search simulates the infinite-array query.
t=int(input());a=list(map(int,input().split()));l,r=0,len(a)-1
while l<=r:
 m=(l+r)//2
 if a[m]==t:print(m);break
 if a[m]<t:l=m+1
 else:r=m-1
else:print(-1)
