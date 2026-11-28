# problem title : Find Triplet with Given Sum
# Fix one value and use two pointers for the remaining two sorted values.
n,t=map(int,input().split());a=list(map(int,input().split()));ok=False
for i in range(n-2):
 l,r=i+1,n-1
 while l<r:
  s=a[i]+a[l]+a[r]
  if s==t:ok=True;break
  if s<t:l+=1
  else:r-=1
 if ok:break
print("Yes" if ok else "No")
