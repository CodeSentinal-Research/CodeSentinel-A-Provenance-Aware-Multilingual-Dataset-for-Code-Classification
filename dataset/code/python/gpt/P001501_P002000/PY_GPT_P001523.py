# PY_GPT_P001523 - Longest Subarray With Absolute Difference Within Limit
# Problem-specific verified implementation.
from collections import deque
n, limit = map(int, input().split())
a = list(map(int, input().split()))
hi = deque()
lo = deque()
left = best = 0
for right, x in enumerate(a):
    while hi and a[hi[-1]] <= x:
        hi.pop()
    while lo and a[lo[-1]] >= x:
        lo.pop()
    hi.append(right)
    lo.append(right)
    while a[hi[0]] - a[lo[0]] > limit:
        if hi[0] == left:
            hi.popleft()
        if lo[0] == left:
            lo.popleft()
        left += 1
    best = max(best, right - left + 1)
print(best)
