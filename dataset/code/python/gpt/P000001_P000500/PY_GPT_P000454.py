# problem title : Allocate Minimum Number of Pages
# Binary-search the minimum possible maximum pages and greedily count required students.
n,m=map(int,input().split());a=list(map(int,input().split()))
lo,hi=max(a),sum(a)
def ok(cap):
 students=1;cur=0
 for x in a:
  if cur+x>cap:students+=1;cur=x
  else:cur+=x
 return students<=m
while lo<hi:
 mid=(lo+hi)//2
 if ok(mid):hi=mid
 else:lo=mid+1
print(lo)
