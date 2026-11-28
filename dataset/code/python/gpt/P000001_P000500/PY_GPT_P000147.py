# problem title : Print Diagonal Elements of Matrix
# Print both diagonals in their requested order.
n = int(input()); a = [list(map(int, input().split()))[:n] for _ in range(n)]
main = [a[i][i] for i in range(n)]
anti = [a[i][n - 1 - i] for i in range(n)]
print(*main); print(*anti)
