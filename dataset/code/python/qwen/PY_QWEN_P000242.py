n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
zeros = 0
for row in matrix:
    zeros += row.count(0)
print(zeros)
