# problem title : Check if Matrix is Symmetric
# Symmetry means a[i][j] equals a[j][i] for every mirrored pair.
n = int(input()); a = [list(map(int, input().split()))[:n] for _ in range(n)]
symmetric = all(a[i][j] == a[j][i] for i in range(n) for j in range(i + 1, n))
print("Symmetric" if symmetric else "Not Symmetric")
