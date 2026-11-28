
n=int(input());a=list(map(int,input().split()));v=int(input())
from bisect import insort;insort(a,v)
print(*a)
