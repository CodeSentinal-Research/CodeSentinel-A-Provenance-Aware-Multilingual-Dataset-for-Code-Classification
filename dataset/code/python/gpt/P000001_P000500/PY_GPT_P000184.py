# problem title : Longest Subarray with Sum K
# Prefix sums plus earliest occurrence gives the longest sum-K interval.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
first = {0: 0}; prefix = best = 0
for i, x in enumerate(a, 1):
    prefix += x
    if prefix - k in first: best = max(best, i - first[prefix - k])
    first.setdefault(prefix, i)
print(best)
