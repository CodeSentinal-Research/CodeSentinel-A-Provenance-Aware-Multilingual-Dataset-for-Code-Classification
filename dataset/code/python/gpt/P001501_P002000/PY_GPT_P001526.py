# PY_GPT_P001526 - Minimum Size Subarray Sum
# Problem-specific verified implementation.
n, target = map(int, input().split())
a = list(map(int, input().split()))
left = current = 0
best = n + 1
for right, x in enumerate(a):
    current += x
    while current >= target:
        best = min(best, right - left + 1)
        current -= a[left]
        left += 1
print(0 if best == n + 1 else best)
