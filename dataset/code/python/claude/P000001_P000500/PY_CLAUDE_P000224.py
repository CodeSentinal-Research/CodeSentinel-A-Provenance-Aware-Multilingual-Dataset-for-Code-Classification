
n = int(input())
jobs = [tuple(map(int, input().split())) for _ in range(n)]
jobs.sort(key=lambda x: -x[2])
max_d = max(j[1] for j in jobs)
slot = [-1]*(max_d+1)
count = profit = 0
for jid, d, p in jobs:
    for t in range(min(max_d, d), 0, -1):
        if slot[t] == -1:
            slot[t] = jid; count += 1; profit += p; break
print(count, profit)
