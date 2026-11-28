# problem title : Longest Increasing Subarray
# Count the longest contiguous run where each next element is larger.
n = int(input()); a = list(map(int, input().split()))[:n]
best = run = 1
for i in range(1, n):
    run = run + 1 if a[i] > a[i - 1] else 1
    best = max(best, run)
print(best)
