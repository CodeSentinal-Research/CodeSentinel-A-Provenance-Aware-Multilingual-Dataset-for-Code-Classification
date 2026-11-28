n = int(input())
strs = [input().strip() for _ in range(n)]
groups = {}
for s in strs:
    key = "".join(sorted(s))
    if key not in groups:
        groups[key] = []
    groups[key].append(s)
for key in groups:
    print(" ".join(groups[key]))
