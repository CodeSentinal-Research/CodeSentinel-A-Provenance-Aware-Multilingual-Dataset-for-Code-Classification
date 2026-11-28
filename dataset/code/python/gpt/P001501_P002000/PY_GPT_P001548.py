# PY_GPT_P001548 - Window With Highest Product (Positive Numbers)
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
product = 1
for value in nums[:k]:
    product *= value
best = product
for right in range(k, n):
    product *= nums[right]
    product //= nums[right - k]
    best = max(best, product)
print(best)
