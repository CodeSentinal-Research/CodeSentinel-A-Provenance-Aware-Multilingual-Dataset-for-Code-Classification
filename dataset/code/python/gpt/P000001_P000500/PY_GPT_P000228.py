# problem title : Search in a Row-wise Column-wise Sorted Matrix
# Start at the top-right corner; each comparison removes one row or one column.
r,c,t=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; i=0;j=c-1; ok=False
while i<r and j>=0:
    if a[i][j]==t:ok=True;break
    if a[i][j]>t:j-=1
    else:i+=1
print("Found" if ok else "Not Found")
