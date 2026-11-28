# PY_GPT_P001504 - Longest Nice Subarray
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
left = mask = best = 0
for right, x in enumerate(a):
    while mask & x:
        mask ^= a[left]
        left += 1
    mask |= x
    best = max(best, right - left + 1)
print(best)
