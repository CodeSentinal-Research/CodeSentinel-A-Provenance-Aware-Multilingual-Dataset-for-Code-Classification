# PY_GPT_P001582 - Longest Binary Subarray With At Most K Zeros
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
left = zeros = best = 0
for right, x in enumerate(a):
    zeros += x == 0
    while zeros > k:
        zeros -= a[left] == 0
        left += 1
    best = max(best, right - left + 1)
print(best)
