# problem title : Find Transition Point
# The first one in a 0...0,1...1 array is a lower-bound search.
n=int(input());a=list(map(int,input().split()));l,r=0,n
while l<r:
 m=(l+r)//2
 if a[m]==1:r=m
 else:l=m+1
print(l if l<n else -1)
