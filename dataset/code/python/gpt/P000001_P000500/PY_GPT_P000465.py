# problem title : Find Pair with Given Difference
# A two-pointer scan detects whether two sorted values differ by the requested amount.
n,d=map(int,input().split());a=list(map(int,input().split()));i=j=0;ok=False
while i<n and j<n:
 if i==j:j+=1;continue
 diff=a[j]-a[i]
 if diff==d:ok=True;break
 if diff<d:j+=1
 else:i+=1
print("Yes" if ok else "No")
