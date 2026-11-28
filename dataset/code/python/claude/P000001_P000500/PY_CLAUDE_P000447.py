
n,x=map(int,input().split())
a=list(map(int,input().split()))
import bisect
lo=bisect.bisect_left(a,x);hi=bisect.bisect_right(a,x)-1
if lo<=hi and a[lo]==x: print(lo,hi)
else: print(-1,-1)
