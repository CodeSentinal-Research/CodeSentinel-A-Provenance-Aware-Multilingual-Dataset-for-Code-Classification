s = input().strip()
from collections import deque, Counter
counts = Counter()
q = deque()
res = []
for c in s:
    counts[c] += 1
    q.append(c)
    while q and counts[q[0]] > 1:
        q.popleft()
    res.append(q[0] if q else '#')
print("".join(res))
