
r, c = map(int, input().split())
best_row, best_cnt = -1, -1
for i in range(r):
    row = list(map(int, input().split()))
    cnt = sum(row)
    if cnt > best_cnt: best_cnt = cnt; best_row = i
print(best_row)
