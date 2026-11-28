# PY_GPT_P001546 - Longest Alternating Even-Odd Subarray
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
length = best = 0
for i, x in enumerate(a):
    length = length + 1 if i and (x - a[i - 1]) % 2 else 1
    best = max(best, length)
print(best)
