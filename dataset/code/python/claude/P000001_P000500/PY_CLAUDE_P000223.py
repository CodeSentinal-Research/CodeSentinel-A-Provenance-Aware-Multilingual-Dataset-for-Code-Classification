
n = int(input())
acts = [tuple(map(int, input().split())) for _ in range(n)]
acts.sort(key=lambda x: x[1])
count, end = 1, acts[0][1]
for s, e in acts[1:]:
    if s >= end: count += 1; end = e
print(count)
