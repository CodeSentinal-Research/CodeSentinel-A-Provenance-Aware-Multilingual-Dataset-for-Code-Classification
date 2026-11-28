s = input().strip()
seen = set()
res = []
for c in s:
    if c not in seen:
        res.append(c)
        seen.add(c)
print("".join(res))
