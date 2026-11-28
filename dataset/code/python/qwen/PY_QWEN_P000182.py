n = int(input())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
max_count = max(counts.values())
res = min(x for x, c in counts.items() if c == max_count)
print(res)
