# problem title : Find Minimum Difference
# After sorting, the minimum absolute difference is among adjacent values.
n = int(input()); a = sorted(map(int, input().split()))[:n]
print(min(a[i + 1] - a[i] for i in range(n - 1)))
