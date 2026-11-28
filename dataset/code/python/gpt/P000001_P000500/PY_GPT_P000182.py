# problem title : Find the Most Frequent Element
# Count frequencies and choose the smallest value among tied maxima.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
freq = Counter(a); best_count = max(freq.values())
print(min(x for x, c in freq.items() if c == best_count))
