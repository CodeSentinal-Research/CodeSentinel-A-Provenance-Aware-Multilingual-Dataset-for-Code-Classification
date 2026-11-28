# problem title : Split Array Largest Sum
# Binary-search the largest allowed subarray sum while counting how many pieces are needed.
n,m=map(int,input().split());a=list(map(int,input().split()));lo,hi=max(a),sum(a)
def ok(cap):
 parts=1;cur=0
 for x in a:
  if cur+x>cap:parts+=1;cur=x
  else:cur+=x
 return parts<=m
while lo<hi:
 mid=(lo+hi)//2
 if ok(mid):hi=mid
 else:lo=mid+1
print(lo)
