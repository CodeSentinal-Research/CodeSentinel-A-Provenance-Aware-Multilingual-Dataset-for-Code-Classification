# problem title : Search in 2D Matrix
# Treat the matrix as a flattened sorted array and binary-search its index.
r,c,t=map(int,input().split());a=[list(map(int,input().split())) for _ in range(r)];l,h=0,r*c-1
while l<=h:
 m=(l+h)//2;v=a[m//c][m%c]
 if v==t:print("Found");break
 if v<t:l=m+1
 else:h=m-1
else:print("Not Found")
