# problem title : Count Occurrences using Binary Search
# Two boundary binary searches give the occurrence count.
n,t=map(int,input().split());a=list(map(int,input().split()))
def bound(first):
 l,r=0,n;ans=n
 while l<r:
  m=(l+r)//2
  if a[m]>t or (first and a[m]==t): r=m
  else:l=m+1
 return l
lo=bound(True);hi=bound(False);print(hi-lo)
