# problem title : Maximum Sum of Two Non-Overlapping Subarrays
# Prefix sums let every fixed-length interval sum be queried in O(1).
n, L, M = map(int, input().split()); a = list(map(int, input().split()))[:n]
p = [0]
for x in a: p.append(p[-1] + x)
def window(i, length): return p[i + length] - p[i]
best = -10**30
for i in range(n - L + 1):
    for j in range(n - M + 1):
        if i + L <= j or j + M <= i:
            best = max(best, window(i, L) + window(j, M))
print(best)
