# problem title : Largest Sum Contiguous Increasing Subarray
# Extend an increasing run while adjacent values strictly rise.
n = int(input()); a = list(map(int, input().split()))[:n]
best = current = a[0]
for i in range(1, n):
    if a[i] > a[i - 1]: current += a[i]
    else: current = a[i]
    best = max(best, current)
print(best)
