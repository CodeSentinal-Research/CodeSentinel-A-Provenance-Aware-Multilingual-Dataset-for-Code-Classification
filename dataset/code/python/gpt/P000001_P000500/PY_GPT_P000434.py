# problem title : Binary Search Last Occurrence
# Continue searching right after a match to locate the last occurrence.
n,t=map(int,input().split());a=list(map(int,input().split()));l,r=0,n-1;ans=-1
while l<=r:
    m=(l+r)//2
    if a[m]<=t:
        if a[m]==t:ans=m
        l=m+1
    else:r=m-1
print(ans)
