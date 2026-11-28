# PY_GPT_P001549 - Count Windows With All Positive Numbers
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k = data[:2]
nums = data[2:n + 2]
bad = sum((value <= 0 for value in nums[:k]))
answer = int(bad == 0)
for right in range(k, n):
    bad += nums[right] <= 0
    bad -= nums[right - k] <= 0
    answer += bad == 0
print(answer)
