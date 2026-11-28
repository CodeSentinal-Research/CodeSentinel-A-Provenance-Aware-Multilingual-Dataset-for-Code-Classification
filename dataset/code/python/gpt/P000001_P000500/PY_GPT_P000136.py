# problem title : Find All Duplicates
# Frequency counting identifies values that occur exactly twice.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
count = Counter(a)
print(*[x for x in sorted(count) if count[x] == 2])
