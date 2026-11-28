# problem title : Sort a Matrix
# Flatten, sort, and refill the matrix row by row.
r, c = map(int, input().split()); values = []
for _ in range(r): values.extend(map(int, input().split()))
values.sort()
for i in range(r): print(*values[i * c:(i + 1) * c])
