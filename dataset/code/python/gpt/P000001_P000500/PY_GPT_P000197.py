# problem title : Find Smallest Sum of Contiguous Subarray of Size K
# The same sliding-window idea can minimize a fixed-size sum.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
window = sum(a[:k]); smallest = window
for i in range(k, n):
    window += a[i] - a[i - k]
    smallest = min(smallest, window)
print(smallest)
