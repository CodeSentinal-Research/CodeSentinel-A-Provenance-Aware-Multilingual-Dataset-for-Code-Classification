# PY_GPT_P001585 - Maximum Frequency After At Most K Increments
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = sorted(map(int, input().split()))
left = total = best = 0
for right, x in enumerate(a):
    total += x
    while x * (right - left + 1) - total > k:
        total -= a[left]
        left += 1
    best = max(best, right - left + 1)
print(best)
