# problem title : Find the First Non-Repeating Element
# Count first, then scan again to preserve original order.
n = int(input()); a = list(map(int, input().split()))[:n]
from collections import Counter
counts = Counter(a)
print(next((x for x in a if counts[x] == 1), -1))
