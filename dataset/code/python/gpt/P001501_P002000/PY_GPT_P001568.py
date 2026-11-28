# PY_GPT_P001568 - Longest Subarray of Ones After Deleting One Element
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n = data[0]
nums = data[1:n + 1]
left = 0
zeros = 0
best = 0
for right, value in enumerate(nums):
    zeros += value == 0
    while zeros > 1:
        zeros -= nums[left] == 0
        left += 1
    best = max(best, right - left)
print(best)
