# PY_GPT_P001566 - Sliding Window Minimum
# Problem-specific verified implementation.
from collections import deque
n, k = map(int, input().split())
a = list(map(int, input().split()))
q = deque()
out = []
for i, x in enumerate(a):
    while q and a[q[-1]] >= x:
        q.pop()
    q.append(i)
    while q[0] <= i - k:
        q.popleft()
    if i >= k - 1:
        out.append(a[q[0]])
print(*out)
