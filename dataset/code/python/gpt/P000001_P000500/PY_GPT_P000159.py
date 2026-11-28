# problem title : Smallest Sum Contiguous Subarray
# Kadane's minimum variant finds the most negative contiguous sum.
n = int(input()); a = list(map(int, input().split()))[:n]
lowest = current = a[0]
for x in a[1:]:
    current = min(x, current + x)
    lowest = min(lowest, current)
print(lowest)
