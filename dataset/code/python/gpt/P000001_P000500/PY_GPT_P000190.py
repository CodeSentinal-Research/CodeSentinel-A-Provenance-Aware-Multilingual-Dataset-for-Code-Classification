# problem title : Find Duplicate in Array of N+1 Elements
# Count occurrences; the problem guarantees exactly one duplicate value.
n = int(input()); a = list(map(int, input().split()))[:n + 1]
from collections import Counter
print(next(x for x, c in Counter(a).items() if c > 1))
