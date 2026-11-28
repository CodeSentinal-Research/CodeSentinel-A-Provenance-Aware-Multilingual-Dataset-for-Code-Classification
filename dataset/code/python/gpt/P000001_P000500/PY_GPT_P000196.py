# problem title : Find Largest Sum of Contiguous Subarray of Size K
# A sliding window updates a size-K sum by removing its left value.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
current = sum(a[:k]); best = current
for i in range(k, n):
    current += a[i] - a[i - k]
    best = max(best, current)
print(best)
