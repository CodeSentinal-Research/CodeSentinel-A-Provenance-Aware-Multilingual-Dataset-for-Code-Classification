# problem title : Maximum Subarray Sum (Kadane)
# Kadane's algorithm tracks the best subarray ending at each position.
n = int(input()); a = list(map(int, input().split()))[:n]
best = current = a[0]
for x in a[1:]:
    current = max(x, current + x)
    best = max(best, current)
print(best)
