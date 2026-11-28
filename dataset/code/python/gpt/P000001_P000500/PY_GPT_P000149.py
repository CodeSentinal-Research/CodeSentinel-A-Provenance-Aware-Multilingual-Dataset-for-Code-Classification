# problem title : Row with Maximum Number of 1s
# Count ones in each sorted binary row and keep the first maximum index.
r, c = map(int, input().split()); rows = [list(map(int, input().split()))[:c] for _ in range(r)]
best_row = max(range(r), key=lambda i: sum(rows[i]))
print(best_row)
