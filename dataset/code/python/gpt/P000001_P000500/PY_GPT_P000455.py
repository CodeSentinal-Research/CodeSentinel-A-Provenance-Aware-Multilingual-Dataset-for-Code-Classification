# problem title : Capacity to Ship Packages
# Binary search the smallest shipping capacity that finishes within D days.
n,d=map(int,input().split());a=list(map(int,input().split()));lo,hi=max(a),sum(a)
def ok(cap):
 days=1;cur=0
 for x in a:
  if cur+x>cap:days+=1;cur=x
  else:cur+=x
 return days<=d
while lo<hi:
 m=(lo+hi)//2
 if ok(m):hi=m
 else:lo=m+1
print(lo)
