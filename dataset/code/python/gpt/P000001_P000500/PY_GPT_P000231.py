# problem title : Print Elements in Sorted Order of Matrix
# Flattening and sorting gives the matrix values in nondecreasing order.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; print(*sorted(v for row in a for v in row))
