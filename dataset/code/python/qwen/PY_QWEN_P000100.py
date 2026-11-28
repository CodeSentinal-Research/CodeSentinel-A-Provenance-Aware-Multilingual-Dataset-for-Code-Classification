n = int(input())
for i in range(n):
    row = [1]
    for j in range(1, i + 1):
        row.append(row[-1] * (i - j + 1) // j)
    print(" ".join(map(str, row)))
