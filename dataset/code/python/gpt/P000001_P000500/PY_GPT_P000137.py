# problem title : Find the Duplicate Number
# XOR the input with the expected 1..N range to cancel all non-duplicate values.
n = int(input()); a = list(map(int, input().split()))[:n + 1]
from collections import Counter
counts = Counter(a)
print(next(x for x in counts if counts[x] > 1))
