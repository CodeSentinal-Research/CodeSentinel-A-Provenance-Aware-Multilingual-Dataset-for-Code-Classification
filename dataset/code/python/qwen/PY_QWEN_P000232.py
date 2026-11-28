rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
flat = sorted([x for row in matrix for x in row])
print(flat[(rows * cols) // 2])
