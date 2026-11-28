# problem title : Binary Search on Answer for Aggressive Cows
# Binary-search the largest minimum stall distance and greedily place cows.
n,c=map(int,input().split());a=sorted(map(int,input().split()));lo,hi=0,a[-1]-a[0]
def ok(d):
 used=1;last=a[0]
 for x in a[1:]:
  if x-last>=d:used+=1;last=x
 return used>=c
while lo<hi:
 m=(lo+hi+1)//2
 if ok(m):lo=m
 else:hi=m-1
print(lo)
