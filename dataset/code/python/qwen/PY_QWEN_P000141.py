n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
rotated = [[matrix[n - 1 - j][i] for j in range(n)] for i in range(n)]
for row in rotated:
    print(" ".join(map(str, row)))
