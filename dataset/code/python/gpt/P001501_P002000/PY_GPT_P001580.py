# PY_GPT_P001580 - Longest Subarray With At Most K Odd Numbers
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
left = odd = best = 0
for right, x in enumerate(a):
    odd += x % 2
    while odd > k:
        odd -= a[left] % 2
        left += 1
    best = max(best, right - left + 1)
print(best)
