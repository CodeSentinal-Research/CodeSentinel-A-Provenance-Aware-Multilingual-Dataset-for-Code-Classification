# problem title : Three Sum Closest
# Sorting lets a two-pointer scan find the closest three-number sum.
n, target = map(int, input().split()); a = sorted(map(int, input().split()))[:n]
best = a[0] + a[1] + a[2]
for i in range(n - 2):
    l, r = i + 1, n - 1
    while l < r:
        total = a[i] + a[l] + a[r]
        if abs(total - target) < abs(best - target): best = total
        if total < target: l += 1
        elif total > target: r -= 1
        else: print(total); raise SystemExit
print(best)
