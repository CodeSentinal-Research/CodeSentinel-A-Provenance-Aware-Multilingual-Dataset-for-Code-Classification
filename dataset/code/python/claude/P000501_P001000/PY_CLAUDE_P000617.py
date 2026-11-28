
n=int(input());a=list(map(int,input().split()))
from bisect import bisect_left,bisect_right
from sortedcontainers import SortedList
if n==1: print(1);exit()
odd_reach=[False]*n;even_reach=[False]*n
odd_reach[n-1]=even_reach[n-1]=True
sl=SortedList(key=lambda x:x[0])
sl.add((a[n-1],n-1))
for i in range(n-2,-1,-1):

    candidates=[x for x in sl if x[0]>=a[i]]
    if candidates: j=min(candidates,key=lambda x:(x[0],x[1]))[1];odd_reach[i]=even_reach[j]

    candidates2=[x for x in sl if x[0]<=a[i]]
    if candidates2: j2=max(candidates2,key=lambda x:(x[0],-x[1]))[1];even_reach[i]=odd_reach[j2]
    sl.add((a[i],i))
print(sum(odd_reach))
