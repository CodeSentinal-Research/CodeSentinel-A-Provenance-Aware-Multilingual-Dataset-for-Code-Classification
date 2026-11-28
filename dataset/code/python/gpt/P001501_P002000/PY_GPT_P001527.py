# PY_GPT_P001527 - Minimum Positive Sum Subarray
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
from collections import deque
prefix = [0]
for x in a:
    prefix.append(prefix[-1] + x)
dq = deque()
best = n + 1
for i, total in enumerate(prefix):
    while dq and total > prefix[dq[0]]:
        best = min(best, i - dq.popleft())
    while dq and prefix[dq[-1]] >= total:
        dq.pop()
    dq.append(i)
print(-1 if best == n + 1 else best)
