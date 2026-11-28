# problem title : Rotate Matrix 90 Degrees Clockwise
# Transpose first, then reverse each row to rotate clockwise.
n = int(input()); matrix = [list(map(int, input().split()))[:n] for _ in range(n)]
rotated = [list(row) for row in zip(*matrix[::-1])]
for row in rotated: print(*row)
