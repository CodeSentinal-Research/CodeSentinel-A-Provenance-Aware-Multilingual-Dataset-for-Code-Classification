# PY_GPT_P001581 - Longest Subarray With At Most K Negative Numbers
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
left = negative = best = 0
for right, x in enumerate(a):
    negative += x < 0
    while negative > k:
        negative -= a[left] < 0
        left += 1
    best = max(best, right - left + 1)
print(best)
