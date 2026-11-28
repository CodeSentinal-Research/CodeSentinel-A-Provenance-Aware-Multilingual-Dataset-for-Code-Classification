# PY_GPT_P001547 - Maximum Number of Odd Elements in a Window
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
odd = sum((value % 2 for value in nums[:k]))
best = odd
for right in range(k, n):
    odd += nums[right] % 2
    odd -= nums[right - k] % 2
    best = max(best, odd)
print(best)
