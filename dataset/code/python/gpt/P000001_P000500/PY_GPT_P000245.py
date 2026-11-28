# problem title : Print Lower Triangular Matrix
# Keep values on and below the main diagonal and zero the upper triangle.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]
for i in range(n): print(*(a[i][j] if j<=i else 0 for j in range(n)))
