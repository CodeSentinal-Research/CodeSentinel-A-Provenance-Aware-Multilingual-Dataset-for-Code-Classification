# problem title : Relative Sort Array
# Emit values in array2 order, then append unused values in ascending order.
m, n = map(int, input().split()); a = list(map(int, input().split()))[:m]; b = list(map(int, input().split()))[:n]
from collections import Counter
count = Counter(a); out = []
for x in b:
    out.extend([x] * count.pop(x, 0))
out.extend(sorted(count.elements()))
print(*out)
