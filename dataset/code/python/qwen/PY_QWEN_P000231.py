n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
flat = sorted([x for row in matrix for x in row])
print(" ".join(map(str, flat)))
