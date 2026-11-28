# problem title : Print Pascal Triangle
# Build each Pascal row from the previous row using combinations.
rows = int(input())
row = [1]
for r in range(rows):
    print(*row)
    nxt = [1]
    for i in range(len(row) - 1):
        nxt.append(row[i] + row[i + 1])
    if r + 1 < rows: nxt.append(1)
    row = nxt
