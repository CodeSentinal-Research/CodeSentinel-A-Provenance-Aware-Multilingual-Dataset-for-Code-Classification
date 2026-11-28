# problem title : Find Peak Element in 2D Matrix
# A matrix peak is searched by choosing the maximum in the middle column and comparing neighbors.
r,c=map(int,input().split());a=[list(map(int,input().split())) for _ in range(r)];lo,hi=0,c-1
while lo<=hi:
 m=(lo+hi)//2;i=max(range(r),key=lambda x:a[x][m]); left=a[i][m-1] if m else -10**18;right=a[i][m+1] if m+1<c else -10**18
 if a[i][m]>=left and a[i][m]>=right:print(a[i][m]);break
 if left>a[i][m]:hi=m-1
 else:lo=m+1
