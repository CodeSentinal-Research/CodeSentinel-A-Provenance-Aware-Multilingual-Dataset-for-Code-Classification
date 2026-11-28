n = int(input())
acts = [tuple(map(int, input().split())) for _ in range(n)]
acts.sort(key=lambda x: x[1])
count = 1
curr_end = acts[0][1]
for i in range(1, n):
    if acts[i][0] >= curr_end:
        count += 1
        curr_end = acts[i][1]
print(count)
