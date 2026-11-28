
n,x=map(int,input().split())
a=list(map(int,input().split()))
import bisect
print(bisect.bisect_right(a,x)-bisect.bisect_left(a,x))
