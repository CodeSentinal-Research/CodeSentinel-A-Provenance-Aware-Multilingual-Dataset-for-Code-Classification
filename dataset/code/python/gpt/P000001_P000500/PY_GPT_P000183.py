# problem title : Count Distinct Elements in Every Window
# A sliding window maintains counts as one element enters and one leaves.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
from collections import defaultdict
count = defaultdict(int); distinct = 0; out = []
for i, x in enumerate(a):
    if count[x] == 0: distinct += 1
    count[x] += 1
    if i >= k:
        old = a[i - k]; count[old] -= 1
        if count[old] == 0: distinct -= 1
    if i >= k - 1: out.append(distinct)
print(*out)
