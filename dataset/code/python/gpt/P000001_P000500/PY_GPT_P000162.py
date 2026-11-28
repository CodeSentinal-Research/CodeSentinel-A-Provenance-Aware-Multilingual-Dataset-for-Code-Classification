# problem title : Count Pairs with Given Sum
# Count complements with a frequency table as the array is scanned.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
from collections import defaultdict
seen = defaultdict(int); total = 0
for x in a:
    total += seen[target - x]
    seen[x] += 1
print(total)
