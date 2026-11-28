n, target = map(int, input().split())
arr = list(map(int, input().split()))
seen = set()
pairs = set()
for x in arr:
    if target - x in seen:
        pairs.add((min(x, target - x), max(x, target - x)))
    seen.add(x)
for p in sorted(list(pairs)):
    print(p[0], p[1])
