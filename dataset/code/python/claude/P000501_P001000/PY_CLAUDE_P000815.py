
n=int(input());a=list(map(int,input().split()));t=int(input())
from bisect import bisect_left,bisect_right
l=bisect_left(a,t);r=bisect_right(a,t)-1
print(l if l<=r else -1,r if l<=r else -1)
