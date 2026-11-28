n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
main_diag = [matrix[i][i] for i in range(n)]
anti_diag = [matrix[i][n - 1 - i] for i in range(n)]
print(" ".join(map(str, main_diag)))
print(" ".join(map(str, anti_diag)))
