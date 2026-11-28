# PY_GPT_P001545 - Minimum Difference Between Maximum and Minimum in Every Window
# Problem-specific verified implementation.
import sys
from collections import deque
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
max_q = deque()
min_q = deque()
best = float('inf')
for i, value in enumerate(nums):
    while max_q and nums[max_q[-1]] <= value:
        max_q.pop()
    max_q.append(i)
    while min_q and nums[min_q[-1]] >= value:
        min_q.pop()
    min_q.append(i)
    if max_q[0] <= i - k:
        max_q.popleft()
    if min_q[0] <= i - k:
        min_q.popleft()
    if i >= k - 1:
        best = min(best, nums[max_q[0]] - nums[min_q[0]])
print(best)
