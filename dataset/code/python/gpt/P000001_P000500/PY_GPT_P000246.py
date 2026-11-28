# problem title : Print Upper Triangular Matrix
# Keep values on and above the main diagonal and zero the lower triangle.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]
for i in range(n): print(*(a[i][j] if j>=i else 0 for j in range(n)))
