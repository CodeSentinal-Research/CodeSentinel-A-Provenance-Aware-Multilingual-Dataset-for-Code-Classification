s = input().strip()
k = int(input())
counts = {}
max_count = 0
start = 0
max_len = 0
for end, c in enumerate(s):
    counts[c] = counts.get(c, 0) + 1
    max_count = max(max_count, counts[c])
    if end - start + 1 - max_count > k:
        counts[s[start]] -= 1
        start += 1
    max_len = max(max_len, end - start + 1)
print(max_len)
