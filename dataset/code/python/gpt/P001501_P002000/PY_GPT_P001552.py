# PY_GPT_P001552 - Smallest Subarray With Sum Greater Than X
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, x = data[:2]
nums = data[2:n + 2]
left = 0
total = 0
best = n + 1
for right, value in enumerate(nums):
    total += value
    while total > x:
        best = min(best, right - left + 1)
        total -= nums[left]
        left += 1
print(-1 if best == n + 1 else best)
