s = input().strip()
last_seen = {}
start = 0
max_len = 0
for i, c in enumerate(s):
    if c in last_seen and last_seen[c] >= start:
        start = last_seen[c] + 1
    max_len = max(max_len, i - start + 1)
    last_seen[c] = i
print(max_len)
