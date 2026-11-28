# problem title : Chocolate Distribution Problem
# Sorting makes the best K-packet group appear in a contiguous sorted window.
n, k = map(int, input().split()); a = sorted(map(int, input().split()))[:n]
print(min(a[i + k - 1] - a[i] for i in range(n - k + 1)))
