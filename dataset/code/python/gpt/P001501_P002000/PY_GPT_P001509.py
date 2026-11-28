# PY_GPT_P001509 - Longest Subarray of Ones After Deleting One Element
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
left = zeros = best = 0
for right, x in enumerate(a):
    zeros += x == 0
    while zeros > 1:
        zeros -= a[left] == 0
        left += 1
    best = max(best, right - left)
print(best)
