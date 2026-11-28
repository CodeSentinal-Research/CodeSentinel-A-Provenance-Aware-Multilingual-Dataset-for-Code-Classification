# problem title : Valid Perfect Square using Binary Search
# A perfect square has an integer square root whose square equals the input.
n=int(input());l,r=1,n
while l<=r:
 m=(l+r)//2
 if m*m==n:print("Yes");break
 if m*m<n:l=m+1
 else:r=m-1
else:print("No")
