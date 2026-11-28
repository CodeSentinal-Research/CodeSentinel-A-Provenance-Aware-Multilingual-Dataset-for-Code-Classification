# problem title : Transpose of a Matrix
# Zip columns together to form the transpose.
r, c = map(int, input().split()); m = [list(map(int, input().split()))[:c] for _ in range(r)]
for row in zip(*m): print(*row)
