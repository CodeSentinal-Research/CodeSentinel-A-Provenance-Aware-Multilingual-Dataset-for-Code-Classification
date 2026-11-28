n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
is_orth = True
for i in range(n):
    for j in range(n):
        val = 0
        for k in range(n):
            val += matrix[i][k] * matrix[j][k]
        if i == j and val != 1:
            is_orth = False
        elif i != j and val != 0:
            is_orth = False
print("Yes" if is_orth else "No")
