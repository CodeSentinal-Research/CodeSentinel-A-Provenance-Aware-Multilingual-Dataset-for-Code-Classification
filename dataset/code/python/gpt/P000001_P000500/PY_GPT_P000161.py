# problem title : Find All Pairs with Given Sum
# Sort and use two pointers, skipping duplicate values to keep pairs unique.
n, target = map(int, input().split()); a = sorted(map(int, input().split()))[:n]
l, r = 0, n - 1; pairs = []
while l < r:
    s = a[l] + a[r]
    if s == target:
        pairs.append((a[l], a[r])); left_val, right_val = a[l], a[r]
        while l < r and a[l] == left_val: l += 1
        while l < r and a[r] == right_val: r -= 1
    elif s < target: l += 1
    else: r -= 1
for x, y in pairs: print(x, y)
