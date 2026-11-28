# PY_GPT_P001544 - Count Windows With Sum Greater Than X
# Problem-specific verified implementation.
import sys
data = list(map(int, sys.stdin.read().split()))
n, k, x = data[:3]
nums = data[3:n + 3]
current = sum(nums[:k])
answer = int(current > x)
for right in range(k, n):
    current += nums[right] - nums[right - k]
    answer += current > x
print(answer)
