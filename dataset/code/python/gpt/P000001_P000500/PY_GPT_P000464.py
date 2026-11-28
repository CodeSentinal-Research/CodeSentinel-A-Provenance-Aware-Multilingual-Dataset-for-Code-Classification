# problem title : Find Closest Element
# Binary search the insertion point and compare its two nearest neighbors.
n,t=map(int,input().split());a=list(map(int,input().split()));import bisect;i=bisect.bisect_left(a,t)
if i==0:ans=a[0]
elif i==n:ans=a[-1]
else:ans=a[i] if abs(a[i]-t)<abs(a[i-1]-t) else a[i-1]
print(ans)
