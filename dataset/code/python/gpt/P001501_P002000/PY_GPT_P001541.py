# PY_GPT_P001541 - Maximum Sum of K Consecutive Elements
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
window = sum(nums[:k])
best = window
for right in range(k, n):
    window += nums[right] - nums[right - k]
    best = max(best, window)
print(best)
