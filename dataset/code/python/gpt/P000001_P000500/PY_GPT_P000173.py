# problem title : Find Maximum Difference
# Keep the smallest value so far and maximize a later value minus it.
n = int(input()); a = list(map(int, input().split()))[:n]
small = a[0]; best = a[1] - a[0]
for x in a[1:]:
    best = max(best, x - small); small = min(small, x)
print(best)
