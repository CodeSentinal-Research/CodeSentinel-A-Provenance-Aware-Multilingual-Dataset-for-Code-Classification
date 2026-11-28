# problem title : Pivot Index
# At a pivot, the sum on its left equals the sum on its right.
n=int(input()); a=list(map(int,input().split())); total=sum(a); left=0; ans=-1
for i,x in enumerate(a):
    if left==total-left-x: ans=i; break
    left+=x
print(ans)
