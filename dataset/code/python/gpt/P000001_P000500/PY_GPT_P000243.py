# problem title : Search in a Sorted Matrix Efficiently
# Use the top-right search rule for a matrix sorted across rows and columns.
r,c,t=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; i=0;j=c-1
while i<r and j>=0 and a[i][j]!=t:
    if a[i][j]>t:j-=1
    else:i+=1
print("Found" if i<r and j>=0 else "Not Found")
