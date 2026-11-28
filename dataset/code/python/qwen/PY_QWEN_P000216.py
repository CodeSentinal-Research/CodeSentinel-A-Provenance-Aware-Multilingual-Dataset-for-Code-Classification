n = int(input())
arr = list(map(int, input().split()))
counts = {}
first = {}
last = {}
for i, x in enumerate(arr):
    counts[x] = counts.get(x, 0) + 1
    if x not in first:
        first[x] = i
    last[x] = i
max_deg = max(counts.values())
min_len = n
for x, c in counts.items():
    if c == max_deg:
        min_len = min(min_len, last[x] - first[x] + 1)
print(min_len)
