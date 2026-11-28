# problem title : Binary Search
# Classic binary search halves the sorted search interval each step.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1
while l<=r:
    m=(l+r)//2
    if a[m]==t: print(m);break
    if a[m]<t:l=m+1
    else:r=m-1
else: print(-1)
