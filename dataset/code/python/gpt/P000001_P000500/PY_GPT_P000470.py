# problem title : Find Minimum Difference Element
# The nearest value must be one of the two neighbors around the target insertion point.
n,t=map(int,input().split());a=list(map(int,input().split()));import bisect;i=bisect.bisect_left(a,t)
if i==0:print(a[0])
elif i==n:print(a[-1])
else:print(a[i] if abs(a[i]-t)<abs(a[i-1]-t) else a[i-1])
