# PY_GPT_P001543 - Minimum Sum Window
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
current = sum(nums[:k])
best = current
for right in range(k, n):
    current += nums[right] - nums[right - k]
    best = min(best, current)
print(best)
