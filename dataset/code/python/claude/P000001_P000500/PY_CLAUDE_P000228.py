
r, c, t = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
i, j = 0, c-1
while i < r and j >= 0:
    if A[i][j] == t: print(i, j); exit()
    elif A[i][j] > t: j -= 1
    else: i += 1
print(-1, -1)
