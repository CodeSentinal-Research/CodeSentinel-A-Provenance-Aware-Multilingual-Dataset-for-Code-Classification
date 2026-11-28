n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
cand = 0
for i in range(1, n):
    if matrix[cand][i] == 1:
        cand = i
is_cel = True
for i in range(n):
    if i != cand:
        if matrix[cand][i] == 1 or matrix[i][cand] == 0:
            is_cel = False
            break
print(cand if is_cel else -1)
