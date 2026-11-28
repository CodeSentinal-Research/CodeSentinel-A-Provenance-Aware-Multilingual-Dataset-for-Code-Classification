n = int(input())
jobs = []
for _ in range(n):
    jid, dl, pr = input().split()
    jobs.append((int(dl), int(pr)))
jobs.sort(key=lambda x: -x[1])
max_dl = max(j[0] for j in jobs) if jobs else 0
slots = [False] * max_dl
profit = 0
count = 0
for dl, pr in jobs:
    for j in range(min(dl, max_dl) - 1, -1, -1):
        if not slots[j]:
            slots[j] = True
            profit += pr
            count += 1
            break
print(profit, count)
