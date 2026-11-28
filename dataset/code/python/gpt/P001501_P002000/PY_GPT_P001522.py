# PY_GPT_P001522 - Minimum Operations to Reduce X to Zero
# Problem-specific verified implementation.
n, x = map(int, input().split())
a = list(map(int, input().split()))
target = sum(a) - x
if target < 0:
    print(-1)
elif target == 0:
    print(n)
else:
    left = current = longest = 0
    for right, value in enumerate(a):
        current += value
        while current > target:
            current -= a[left]
            left += 1
        if current == target:
            longest = max(longest, right - left + 1)
    print(-1 if longest == 0 else n - longest)
