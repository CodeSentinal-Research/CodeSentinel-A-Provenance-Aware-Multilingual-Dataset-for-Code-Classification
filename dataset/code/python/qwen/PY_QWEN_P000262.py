s = input().strip()
counts = {}
for c in s:
    counts[c] = counts.get(c, 0) + 1
for c in s:
    if counts[c] == 1:
        print(c)
        break
else:
    print(-1)
