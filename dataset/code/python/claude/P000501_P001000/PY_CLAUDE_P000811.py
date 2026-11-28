
n=int(input());a=list(map(int,input().split()));t=int(input())
from bisect import bisect_left
i=bisect_left(a,t)
print(i if i<n and a[i]==t else -1)
