# problem title : Search in Row-wise and Column-wise Sorted Matrix
# Top-right elimination works because rows and columns are both sorted.
r,c,t=map(int,input().split());a=[list(map(int,input().split())) for _ in range(r)];i=0;j=c-1
while i<r and j>=0 and a[i][j]!=t:
 if a[i][j]>t:j-=1
 else:i+=1
print("Found" if i<r and j>=0 else "Not Found")
