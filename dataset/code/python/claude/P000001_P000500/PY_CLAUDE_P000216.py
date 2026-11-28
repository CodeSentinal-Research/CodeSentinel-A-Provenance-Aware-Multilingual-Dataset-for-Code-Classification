
n = int(input())
a = list(map(int, input().split()))
from collections import Counter
freq = Counter(a)
first = {}; last = {}
for i, x in enumerate(a):
    if x not in first: first[x] = i
    last[x] = i
deg = max(freq.values())
res = n
for x, cnt in freq.items():
    if cnt == deg:
        res = min(res, last[x] - first[x] + 1)
print(res)
