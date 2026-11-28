# problem title : Find Triplet with Given Sum
# Sort first, then solve the three-sum existence problem with two pointers.
n, target = map(int, input().split()); a = sorted(map(int, input().split()))[:n]
found = False
for i in range(n - 2):
    l, r = i + 1, n - 1
    while l < r:
        s = a[i] + a[l] + a[r]
        if s == target: found = True; break
        if s < target: l += 1
        else: r -= 1
    if found: break
print("Yes" if found else "No")
