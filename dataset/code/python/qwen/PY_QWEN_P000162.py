n, target = map(int, input().split())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
ans = 0
for x in arr:
    counts[x] -= 1
    if target - x in counts and counts[target - x] > 0:
        ans += counts[target - x]
print(ans)
