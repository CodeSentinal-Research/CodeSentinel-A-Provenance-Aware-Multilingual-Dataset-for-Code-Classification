# problem title : Find All Elements Appearing More Than N/3 Times
# At most two distinct values can occur more than N/3 times; use counting for clarity.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
freq = Counter(a)
print(*sorted(x for x, c in freq.items() if c > n // 3))
