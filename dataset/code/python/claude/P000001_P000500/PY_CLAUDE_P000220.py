
n = int(input())
M = [list(map(int, input().split())) for _ in range(n)]
cand = 0
for i in range(1, n):
    if M[cand][i]: cand = i
for i in range(n):
    if i != cand and (M[cand][i] or not M[i][cand]):
        print(-1); exit()
print(cand)
