# problem title : Maximum Product Subarray
# Track both maximum and minimum products because a negative can flip them.
n = int(input()); a = list(map(int, input().split()))[:n]
hi = lo = best = a[0]
for x in a[1:]:
    if x < 0: hi, lo = lo, hi
    hi = max(x, hi * x); lo = min(x, lo * x); best = max(best, hi)
print(best)
