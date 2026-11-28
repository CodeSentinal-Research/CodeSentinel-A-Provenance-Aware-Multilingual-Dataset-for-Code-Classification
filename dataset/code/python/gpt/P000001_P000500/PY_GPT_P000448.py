# problem title : Square Root using Binary Search
# Binary search finds the largest integer whose square does not exceed n.
n=int(input());l,r=0,n;ans=0
while l<=r:
 m=(l+r)//2
 if m*m<=n:ans=m;l=m+1
 else:r=m-1
print(ans)
