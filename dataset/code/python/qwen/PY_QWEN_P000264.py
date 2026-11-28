s = input().strip()
counts = {}
for c in s:
    counts[c] = counts.get(c, 0) + 1
for c in sorted(counts.keys()):
    print(c, counts[c])
