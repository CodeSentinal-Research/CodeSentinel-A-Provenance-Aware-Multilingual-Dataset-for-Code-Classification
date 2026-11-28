# problem title : Find Position of an Element in Infinite Array
# The provided large sorted array makes ordinary binary search a direct simulation.
t=int(input());a=list(map(int,input().split()));l,r=0,len(a)-1
while l<=r:
 m=(l+r)//2
 if a[m]==t:print(m);break
 if a[m]<t:l=m+1
 else:r=m-1
else:print(-1)
